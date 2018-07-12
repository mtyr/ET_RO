/* ------------------------------------------------------------------------- */
/*	rnInverted_Control.cpp                                                   */
/*	<EV3ライントレース>ソフトウェア開発                                      */
/*	倒立制御クラス                                                           */
/*  倒立制御を担当。走行用計算クラスに計算指示を送り                         */
/*　戻り値をモーター出力に送る                                               */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	番号		更新履歴							日付		氏名		 */
/*	-----------------------------------------------------------------------  */
/*	000000		新規作成							2018/07/02	田邉  周哉	 */
/* ------------------------------------------------------------------------- */

#include "rnInverted_Control.h"
/* ------------------------------------------------------------------------- */
/* 定数宣言                                                                  */
/* ------------------------------------------------------------------------- */
const SINT rnInverted_Control::LOW = 30;        /* 低速                      */
const SINT rnInverted_Control::NORMAL = 50;     /* 通常                      */
const SINT rnInverted_Control::HIGH = 70;       /* 高速                      */

/* ------------------------------------------------------------------------- */
/*	関数名		:rnInverted_Control                                          */
/*	機能名		:倒立走行指示                                                */
/*	機能概要	:倒立制御・走行の流れを持ち、各クラスに指示をする関数        */
/*	引数		:dgStattic_Angular_Velocity_get                              */
/*                              static_anglar_velocity_get                   */
/*								                角速度取得クラス             */
/*			    :dgStatic_Motor_get                                          */
/*                              static_motor_get_left                        */
/*								                モーター取得クラス(左)       */
/*			    :dgStatic_Motor_get                                          */
/*                              static_motor_get_right                       */
/*								                モーター取得クラス(右)       */
/*				:rnCalculation  calculation     走行用計算「管理」クラス     */
/*  戻り値      :無し                                                        */
/*	作成日		:2018/07/02		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
rnInverted_Control::rnInverted_Control(const dgStattic_Angular_Velocity_get* static_anglar_velocity_get,
									   dgStatic_Motor_get* static_motor_get_left,
									   dgStatic_Motor_get* static_motor_get_right,
									   rnCalculation* calculation)
	: gyro_sensor(static_anglar_velocity_get),
	left_wheel(static_motor_get_left),
	right_wheel(static_motor_get_right),
	rn_calculation(calculation),
	i_forward(LOW),
	i_turn(LOW) {
}

/* ------------------------------------------------------------------------- */
/*	関数名		:Run                                                         */
/*	機能名		:倒立走行指示                                                */
/*	機能概要	:倒立制御・走行の流れを持ち、各クラスに指示をする関数        */
/*	引数		:無し                                                        */
/*  戻り値      :無し                                                        */
/*	作成日		:2018/07/02		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
void rnInverted_Control::Run() {
	/* getInstanceを呼び出す */
	class dgStattic_Angular_Velocity_get &gyro_sensor = dgStattic_Angular_Velocity_get::getInstance;
	/* ジャイロセンサ値取得 */
	SSHT s_angle = gyro_sensor->GyroGet();
	/* 右モータ回転角度取得 */
	SINT i_right_wheel_enc = right_wheel->RotationAngleGet();
	/* 左モータ回転角度取得 */
	SINT i_left_wheel_enc = left_wheel->RotationAngleGet();

	/* rnCalculationにデータを渡す */
	rn_calculation->SetCommand(i_forward, i_turn);

	/* バッテリー電圧値を取得する */
	SINT i_battery = dgStatic_Battery_Balance_Amount_Get->VoltageGet();

	/* 左右モーター出力値を得る */
	rn_calculation->Update(s_angle, i_right_wheel_enc, i_left_wheel_enc, i_battery);

	/* 左右モータに回転を指示する（廖さんの関数待ち） */
	// dcMotor_Output->(rn_calculation->GetPwmLeft, rn_calculation->GetPwmright);
}

/* ------------------------------------------------------------------------- */
/*	関数名		:Initialize                                                  */
/*	機能名		:デバイス初期化												 */
/*	機能概要	:バランス走行に必要な数値をリセットする                      */
/*	引数		:無し                                                        */
/*  戻り値      :無し                                                        */
/*	作成日		:2018/07/02		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
void rnInverted_Control::Initialize() {
	SINT i_offset = gyro_sensor->GyroGet();  // ジャイロセンサ値

	/* モータエンコーダをリセットする */
	//廖さんの関数待ち
	/* dcMotor_Output->関数名() */
	//left_wheel.reset();
	//right_wheel.reset();

	/* 倒立振子制御初期化 */
	rn_calculation->Initialize(i_offset);
}

/* ------------------------------------------------------------------------- */
/*	関数名		:SetCommand                                                  */
/*	機能名		:PWM設定                                                     */
/*	機能概要	:走行用計算に渡す値を設定する                                */
/*	引数		:SINT           forward         上記の定数が入る(前進値)     */
/*              :SINT           turn            上記の定数が入る(旋回値)     */
/*  戻り値      :無し                                                        */
/*	作成日		:2018/07/02		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
void rnInverted_Control::SetCommand(SINT forward, SINT turn) {
	i_forward = forward;
	i_turn = turn;
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
