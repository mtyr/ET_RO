/* ------------------------------------------------------------------------- */
/*	rnCalculation_Cpp.h                                                      */
/*	<EV3ライントレース>ソフトウェア開発                                      */
/*	走行用計算実行クラス                                                     */
/*  モーター出力値を計算する                                                 */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	番号		更新履歴							日付		氏名		 */
/*	-----------------------------------------------------------------------  */
/*	000000		新規作成							2018/07/11	田邉  周哉	 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/*概要  : 2輪型倒立振子ロボット「NXTway-GS」バランス制御プログラム
          NXTway-GSのバランス制御には、サーボ制御(状態 + 積分フィードバック)
          という現代制御を適用しています。制御対象の同定および制御器の開発
          にはThe MathWorks社のMATLAB&Simulinkという製品を使用した、
          MBD(モデルベースデザイン/開発)開発手法を用いています。このCプログラムは
          SimulinkモデルからReal-Time Workshop Embedded Coderコード生成標準機能を
          使用して自動生成されたものです。バランス制御器の制御パラメータについては
          ユーザーハンドコード側で定義する必要があります。定義例として、
          nxtOSEK\samples\nxtway_gs\balancer_param.cを参照してください。
          バランス制御アルゴリズムの詳細情報につきましては
          日本語: http://www.cybernet.co.jp/matlab/library/library/detail.php?id=TA060
          英語  : http://www.mathworks.com/matlabcentral/fileexchange/loadFile.do?objectId=19147&objectType=file
          を参照してください。
*/
/* ------------------------------------------------------------------------- */



#include "rnCalculation.h"
#include "balancer_private.h"

/*============================================================================
 * Local macro definitions
 *===========================================================================*/
#define rt_SATURATE(sig,ll,ul)         (((sig) >= (ul)) ? (ul) : (((sig) <= (ll)) ? (ll) : (sig)) )

/*============================================================================
 * Data definitions
 *===========================================================================*/
static FLOT ud_err_theta;          /* 左右車輪の平均回転角度(θ)目標誤差状態値 */
static FLOT ud_psi;                /* 車体ピッチ角度(ψ)状態値 */
static FLOT ud_theta_lpf;          /* 左右車輪の平均回転角度(θ)状態値 */
static FLOT ud_theta_ref;          /* 左右車輪の目標平均回転角度(θ)状態値 */
static FLOT ud_thetadot_cmd_lpf;   /* 左右車輪の目標平均回転角速度(dθ/dt)状態値 */

/*============================================================================
 * Functions
 *===========================================================================*/
//*****************************************************************************
// 関数名  : balance_control
// 引数    :
//   (float)args_cmd_forward : 前進/後進命令。100(前進最大値)～-100(後進最大値)
//   (float)args_cmd_turn    : 旋回命令。100(右旋回最大値)～-100(左旋回最大値)
//   (float)args_gyro        : ジャイロセンサ値
//   (float)args_gyro_offset : ジャイロセンサオフセット値
//   (float)args_theta_m_l   : 左モータエンコーダ値
//   (float)args_theta_m_r   : 右モータエンコーダ値
//   (float)args_battery     : バッテリ電圧値(mV)
// 戻り値  :
//   (char*)ret_pwm_l        : 左モータPWM出力値
//   (char*)ret_pwm_r        : 右モータPWM出力値
// 概要    :  NXTway-GSバランス制御関数。
//            この関数は4msec周期で起動されることを前提に設計されています。
//            なお、ジャイロセンサオフセット値はセンサ個体および通電によるドリフト
//            を伴いますので、適宜補正する必要があります。また、左右の車輪駆動
//            モータは個体差により、同じPWM出力を与えても回転数が異なる場合が
//            あります。その場合は別途補正機能を追加する必要があります。
// 使用例  :
//        /* 最高速直進命令 */
//        balance_control(
//          (float)100,                                  /* 前進最高速命令 */
//          (float)0,                                    /* 無旋回命令 */
//          (float)ecrobot_get_gyro_sensor(NXT_PORT_S4), /* ジャイロセンサ値 */
//          (float)605,                                  /* 車体停止時のジャイロセンサ値 */
//          (float)nxt_motor_get_count(NXT_PORT_C),      /* 左モータエンコーダ値 */
//          (float)nxt_motor_get_count(NXT_PORT_B),      /* 右モータエンコーダ値 */
//          (float)ecrobot_get_battery_voltage(),        /* バッテリ電圧値(mV) */
//          &pwm_l,                                    /* 左モータPWM出力値 */
//          &pwm_r);                                   /* 右モータPWM出力値 */
//*****************************************************************************
void Calculation_Control(float args_cmd_forward, float args_cmd_turn, float
                     args_gyro, float args_gyro_offset, float
                     args_theta_m_l, float args_theta_m_r, float
                     args_battery, signed char *ret_pwm_l, signed char *ret_pwm_r)
{
  {
    FLOT tmp_theta;
	FLOT tmp_theta_lpf;
	FLOT tmp_pwm_r_limiter;
	FLOT tmp_psidot;
	FLOT tmp_pwm_turn;
	FLOT tmp_pwm_l_limiter;
	FLOT tmp_thetadot_cmd_lpf;
	FLOT tmp[4];
	FLOT tmp_theta_0[4];
	SLNG tmp_0;

    /* Sum: '<S8>/Sum' incorporates:
     *  Constant: '<S3>/Constant6'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S8>/Gain2'
     *  Inport: '<Root>/cmd_forward'
     *  Product: '<S3>/Divide'
     *  Product: '<S8>/Product'
     *  Sum: '<S8>/Sum1'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    tmp_thetadot_cmd_lpf = (((args_cmd_forward / CMD_MAX) * K_THETADOT) * (1.0F
      - A_R)) + (A_R * ud_thetadot_cmd_lpf);

    /* Gain: '<S4>/Gain' incorporates:
     *  Gain: '<S4>/deg2rad'
     *  Gain: '<S4>/deg2rad1'
     *  Inport: '<Root>/theta_m_l'
     *  Inport: '<Root>/theta_m_r'
     *  Sum: '<S4>/Sum1'
     *  Sum: '<S4>/Sum4'
     *  Sum: '<S4>/Sum6'
     *  UnitDelay: '<S10>/Unit Delay'
     */
    tmp_theta = (((DEG2RAD * args_theta_m_l) + ud_psi) + ((DEG2RAD *
      args_theta_m_r) + ud_psi)) * 0.5F;

    /* Sum: '<S11>/Sum' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  Gain: '<S11>/Gain2'
     *  Product: '<S11>/Product'
     *  Sum: '<S11>/Sum1'
     *  UnitDelay: '<S11>/Unit Delay'
     */
    tmp_theta_lpf = ((1.0F - A_D) * tmp_theta) + (A_D * ud_theta_lpf);

    /* Gain: '<S4>/deg2rad2' incorporates:
     *  Inport: '<Root>/gyro'
     *  Inport: '<Root>/gyro_offset'
     *  Sum: '<S4>/Sum2'
     */
    tmp_psidot = (args_gyro - args_gyro_offset) * DEG2RAD;

    /* Gain: '<S2>/Gain' incorporates:
     *  Constant: '<S3>/Constant2'
     *  Constant: '<S3>/Constant3'
     *  Constant: '<S6>/Constant'
     *  Constant: '<S9>/Constant'
     *  Gain: '<S1>/FeedbackGain'
     *  Gain: '<S1>/IntegralGain'
     *  Gain: '<S6>/Gain3'
     *  Inport: '<Root>/battery'
     *  Product: '<S2>/Product'
     *  Product: '<S9>/Product'
     *  Sum: '<S1>/Sum2'
     *  Sum: '<S1>/sum_err'
     *  Sum: '<S6>/Sum2'
     *  Sum: '<S9>/Sum'
     *  UnitDelay: '<S10>/Unit Delay'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S5>/Unit Delay'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    tmp[0] = ud_theta_ref;
    tmp[1] = 0.0F;
    tmp[2] = tmp_thetadot_cmd_lpf;
    tmp[3] = 0.0F;
    tmp_theta_0[0] = tmp_theta;
    tmp_theta_0[1] = ud_psi;
    tmp_theta_0[2] = (tmp_theta_lpf - ud_theta_lpf) / EXEC_PERIOD;
    tmp_theta_0[3] = tmp_psidot;
    tmp_pwm_r_limiter = 0.0F;
    for (tmp_0 = 0; tmp_0 < 4; tmp_0++) {
      tmp_pwm_r_limiter += (tmp[tmp_0] - tmp_theta_0[tmp_0]) * K_F[(tmp_0)];
    }

    tmp_pwm_r_limiter = (((K_I * ud_err_theta) + tmp_pwm_r_limiter) /
                         ((BATTERY_GAIN * args_battery) - BATTERY_OFFSET)) *
      100.0F;

    /* Gain: '<S3>/Gain2' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Inport: '<Root>/cmd_turn'
     *  Product: '<S3>/Divide1'
     */
    tmp_pwm_turn = (args_cmd_turn / CMD_MAX) * K_PHIDOT;

    /* Sum: '<S2>/Sum' */
    tmp_pwm_l_limiter = tmp_pwm_r_limiter + tmp_pwm_turn;

    /* Saturate: '<S2>/pwm_l_limiter' */
    tmp_pwm_l_limiter = rt_SATURATE(tmp_pwm_l_limiter, -100.0F, 100.0F);

    /* Outport: '<Root>/pwm_l' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    (*ret_pwm_l) = (signed char)tmp_pwm_l_limiter;

    /* Sum: '<S2>/Sum1' */
    tmp_pwm_r_limiter -= tmp_pwm_turn;

    /* Saturate: '<S2>/pwm_r_limiter' */
    tmp_pwm_r_limiter = rt_SATURATE(tmp_pwm_r_limiter, -100.0F, 100.0F);

    /* Outport: '<Root>/pwm_r' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion6'
     */
    (*ret_pwm_r) = (signed char)tmp_pwm_r_limiter;

    /* Sum: '<S7>/Sum' incorporates:
     *  Gain: '<S7>/Gain'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    tmp_pwm_l_limiter = (EXEC_PERIOD * tmp_thetadot_cmd_lpf) + ud_theta_ref;

    /* Sum: '<S10>/Sum' incorporates:
     *  Gain: '<S10>/Gain'
     *  UnitDelay: '<S10>/Unit Delay'
     */
    tmp_pwm_turn = (EXEC_PERIOD * tmp_psidot) + ud_psi;

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/Gain'
     *  Sum: '<S1>/Sum1'
     *  UnitDelay: '<S5>/Unit Delay'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    tmp_pwm_r_limiter = ((ud_theta_ref - tmp_theta) * EXEC_PERIOD) +
      ud_err_theta;

    /* user code (Update function Body) */
    /* System '<Root>' */
    /* 次回演算用状態量保存処理 */

    /* Update for UnitDelay: '<S5>/Unit Delay' */
    ud_err_theta = tmp_pwm_r_limiter;

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    ud_theta_ref = tmp_pwm_l_limiter;

    /* Update for UnitDelay: '<S8>/Unit Delay' */
    ud_thetadot_cmd_lpf = tmp_thetadot_cmd_lpf;

    /* Update for UnitDelay: '<S10>/Unit Delay' */
    ud_psi = tmp_pwm_turn;

    /* Update for UnitDelay: '<S11>/Unit Delay' */
    ud_theta_lpf = tmp_theta_lpf;
  }
}

//*****************************************************************************
// 関数名  : Calculation_Initialize
// 引数    : 無し
// 戻り値  : 無し
// 概要    : NXTway-GSバランス制御初期化関数。内部状態量変数を初期化します。
//           この関数によりバランス制御機能を初期化する場合は、併せて左右の
//           車輪駆動モーターのエンコーダ値を0にリセットしてください。
// 使用例  :
//		nxt_motor_set_speed(NXT_PORT_C, 0, 1); /* 左モータ停止 */
//		nxt_motor_set_speed(NXT_PORT_B, 0, 1); /* 右モータ停止 */
//		balance_init();						   /* NXTway-GSバランス制御初期化 */
//      /* モータエンコーダ値を0リセットする前にモータが停止していること */
//		nxt_motor_set_count(NXT_PORT_C, 0);    /* 左モータエンコーダ0リセット */
//		nxt_motor_set_count(NXT_PORT_B, 0);    /* 右モータエンコーダ0リセット */
//*****************************************************************************
void Calculation_Initialize(void)
{
  /* Registration code */

  /* states (dwork) */

  /* custom states */
  ud_err_theta = 0.0F;
  ud_theta_ref = 0.0F;
  ud_thetadot_cmd_lpf = 0.0F;
  ud_psi = 0.0F;
  ud_theta_lpf = 0.0F;
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */