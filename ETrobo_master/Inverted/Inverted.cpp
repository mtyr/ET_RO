/*	-----------------------------------------------------------------------	 */
/*	Inverted.cpp															 */
/*	倒立振子のライブラリのラッピング										 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/25	小西 巧	 	 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	includeファイル															 */
/*	-----------------------------------------------------------------------	 */
#include "Inverted.h"
#include "balancer.h"
#include "..\frLog\frLog.h"

#include "..\dgMotor_Get\dgMotor_Get.h"
#include "..\dgBattery_Balance_Amount_Get\dgBattery_Balance_Amount_Get.h"
#include "..\dgAngular_Velocity_Get\dgAngular_Velocity_Get.h"

/*	-----------------------------------------------------------------------	 */
/*	define定義																 */
/*	-----------------------------------------------------------------------	 */
#define GYRO_OFFSET  0     /* ジャイロセンサオフセット値(角速度0[deg/sec]時) */

/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	:Inverted::GetInstance											 */
/* 機能名	:倒立制御：クラス生成											 */
/* 機能概要	:クラスの実態を返す												 */
/* 引数		:void			:なし											 */
/* 戻り値	:frBluetooth	:obj			:クラスの実態					 */
/* 作成日	: 2018/07/01	甲田  啓朗		新規作成						 */
/* ------------------------------------------------------------------------- */
Inverted& Inverted::GetInstance(void)
{
	static Inverted obj;
	return obj;
}
/* ------------------------------------------------------------------------- */
/* 関数名	Inverted::Inverted												 */
/* 機能名	:倒立：なし														 */
/* 機能概要	:なし															 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/25	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
Inverted::Inverted(void){

}

/* ------------------------------------------------------------------------- */
/* 関数名	Inverted::BalanceInit											 */
/* 機能名	:倒立：倒立振子ライブラリの初期化								 */
/* 機能概要	:ライブラリの初期化												 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/25	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
void Inverted::BalanceInit(void)
{
	 /* 走行モーターエンコーダーリセット */
    ev3_motor_reset_counts(EV3_PORT_B);
    ev3_motor_reset_counts(EV3_PORT_C);
	
	/*	ジャイロリセット	*/
	ev3_gyro_sensor_reset(EV3_PORT_4);
	tslp_tsk(100);
	
	balance_init();
}

/* ------------------------------------------------------------------------- */
/* 関数名	Inverted::BalanceInit											 */
/* 機能名	:倒立：倒立振子ライブラリに渡すパラメータ						 */
/* 機能概要	:ライブラリ前進と旋回											 */
/* 引数		:float			:f_drivi	:前進後退値							 */
/*			:float			:f_turning	:旋回値								 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/25	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
void Inverted::DriviParame(FLOT f_drivi,FLOT f_turning)
{
	f_forward	= f_drivi;
	f_turn		= f_turning;
}

/* ------------------------------------------------------------------------- */
/* 関数名	Inverted::~Inverted												 */
/* 機能名	:倒立：倒立振子ライブラリのデストラクタ							 */
/* 機能概要	:なし															 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/25	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
Inverted::~Inverted(void){

}


/* ------------------------------------------------------------------------- */
/* 関数名	Inverted::BalanceControl										 */
/* 機能名	:倒立：倒立振子ライブラリのバランスコントロール					 */
/* 機能概要	:なし															 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/25	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
void Inverted::BalanceControl(void){

	/*	変数宣言-----------------------------------------------------------	 */
	int32_t motor_ang_l;						/*	左モーター値			 */
	int32_t motor_ang_r;						/*	右モーター値			 */
	SINT i_gyro;								/*	ジャイロ値				 */
	SINT i_volt;								/*	電圧値(mV)				 */
	
	/*	クラス宣言---------------------------------------------------------	 */
	/*	ジャイロ	*/
	dgAngular_Velocity_Get &gyro = dgAngular_Velocity_Get::GetInstance();

	/*	電圧	*/
	dgBattery_Balance_Amount_Get &battery =dgBattery_Balance_Amount_Get::GetInstance();

	/*	モーター	*/
	dgMotor_Get &motor=dgMotor_Get::GetInstance();

	/*	ログ	*/
	frLog &log = frLog::GetInstance();

	/*	各センサーの値を取得-----------------------------------------------	 */
	 motor_ang_l = ev3_motor_get_counts(EV3_PORT_C);
     motor_ang_r = ev3_motor_get_counts(EV3_PORT_B);
     i_gyro = ev3_gyro_sensor_get_rate( EV3_PORT_4);
     i_volt = ev3_battery_voltage_mV();
	
	log.LOG(LOG_ID_ERR,"L_motor:%d\r\n",motor_ang_l);
	log.LOG(LOG_ID_ERR,"R_motor:%d\r\n",motor_ang_r);
	
	log.LOG(LOG_ID_ERR,"V:%d\r\n",i_volt);
	log.LOG(LOG_ID_ERR,"gyro:%d\r\n",i_gyro);
	
	BacklashCancel(pwm_L, pwm_R, &motor_ang_l, &motor_ang_r);

	balance_control(f_forward, 					/*	前進					 */
					f_turn, 					/*	旋回					 */
					(FLOT)i_gyro, 				/*	角位置					 */
					(FLOT)GYRO_OFFSET,			/*	基本0(ジャイロオフセット)*/
					(FLOT)motor_ang_l, 			/*	左モーター角位置		 */
					(FLOT)motor_ang_r, 			/*	右モーター角位置		 */
					(FLOT)i_volt,				/*	電圧					 */
					(signed char*)&pwm_L,		/*	左モーター前回出力値	 */
					(signed char*)&pwm_R		/*	右モーター前回出力値	 */
	);
	
	
    /* EV3ではモーター停止時のブレーキ設定が事前にできないため */
    /* 出力0時に、その都度設定する */
	
	/*	左モーター	*/
  	if (pwm_L == 0)
    {
         ev3_motor_stop(EV3_PORT_C, true);
    }
    else
    {
        ev3_motor_set_power(EV3_PORT_C, (int)pwm_L);
    }
    
	/*	右モータ	*/
    if (pwm_R == 0)
    {
         ev3_motor_stop(EV3_PORT_B, true);
    }
    else
    {
        ev3_motor_set_power(EV3_PORT_B, (int)pwm_R);
  	}
	
/*	if(pwm_L==0){
	ev3_motor_set_power(EV3_PORT_C, (int)pwm_L);
	ev3_motor_set_power(EV3_PORT_B, (int)pwm_R);
		
	}else {
	ev3_motor_set_power(EV3_PORT_C, (int)pwm_L);
	ev3_motor_set_power(EV3_PORT_B, (int)pwm_R);
	}*/
	
	//ev3_motor_set_power(EV3_PORT_C, (int)pwm_L);
	//ev3_motor_set_power(EV3_PORT_B, (int)pwm_R);
	
	//log.LOG(LOG_ID_ERR,"L_motor:%d\r\n",(int)pwm_L);
	//log.LOG(LOG_ID_ERR,"R_motor:%d\r\n",(int)pwm_R);
}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	Inverted::BacklashCancel										 */
/* 機能名	:倒立：倒立振子バックラッシュキャンセル							 */
/* 機能概要	:なし															 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/25	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
void Inverted::BacklashCancel(signed char lpwm, signed char rpwm,
							  int32_t *lenc, 	int32_t *renc		){
	/*	クラス宣言---------------------------------------------------------	 */
	//frLog &log = frLog::GetInstance();			/*	ログクラス				 */

    const int BACKLASHHALF = 4;   				/* バックラッシュの半分[deg] */

    if(lpwm < 0) *lenc += BACKLASHHALF;
    else if(lpwm > 0) *lenc -= BACKLASHHALF;

    if(rpwm < 0) *renc += BACKLASHHALF;
    else if(rpwm > 0) *renc -= BACKLASHHALF;
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
