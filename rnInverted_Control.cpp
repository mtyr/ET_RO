/* ------------------------------------------------------------------------- */
/*	rnInverted_Control.cpp													 */
/*	<EV3ライントレース>ソフトウェア開発										 */
/*	倒立制御クラス															 */
/*	倒立制御を担当。走行用計算クラスに計算指示を送り						 */
/*　戻り値をモーター出力に送る												 */
/*																			 */
/*	-----------------------------------------------------------------------	 */
/*	番号		更新履歴							日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000		新規作成							2018/07/02	田邉  周哉	 */
/*	000001		レビュー後修正						2018/07/12	田邉　周哉	 */
/* ------------------------------------------------------------------------- */

/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include "rnInverted_Control.h"

/* ------------------------------------------------------------------------- */
/* 定数宣言																	 */
/* ------------------------------------------------------------------------- */
const SINT rnInverted_Control::LOW = 30;		/* 低速						 */
const SINT rnInverted_Control::NORMAL = 50;		/* 通常						 */
const SINT rnInverted_Control::HIGH = 70;		/* 高速						 */

/* ------------------------------------------------------------------------- */
/*	関数名		:rnInverted_Control											 */
/*	機能名		:コンストラクタ												 */
/*	機能概要	:変数定義とシングルトン定義を行う							 */
/*	引数		:無し														 */
/*	戻り値		:無し														 */
/*	作成日		:2018/07/02		田邉周哉		新規作成					 */
/*				:2018/07/12		田邉周哉		レビュー後修正				 */
/* ------------------------------------------------------------------------- */
rnInverted_Control::rnInverted_Control()
{
	i_forward = LOW;							/* 前進値					 */
	i_turn = LOW;								/* 旋回値					 */
}

/* ------------------------------------------------------------------------- */
/*	関数名		:Run														 */
/*	機能名		:倒立走行指示												 */
/*	機能概要	:倒立制御・走行の流れを持ち、各クラスに指示をする関数		 */
/*	引数		:無し														 */
/*	戻り値		:SINT			FUNK_OK			関数正常終					 */
/*	作成日		:2018/07/02		田邉周哉		新規作成					 */
/*				:2018/07/12		田邉周哉		レビュー後修正				 */
/* ------------------------------------------------------------------------- */
SINT rnInverted_Control::Run() {
	/* シングルトン生成&ジャイロセンサ角位置[deg]取得 */
	dgAngular_Velocity_get &gyro_sensor = dgAngular_Velocity_get::GetInstance();
	SSHT s_angle = gyro_sensor.GyroGet();
	/* シングルトン生成&右モータ回転角度取得 */
	dgMotor_get &right_wheel = dgMotor_get::GetInstance();
	SINT i_right_wheel_enc = right_wheel.RMotorGet();
	/* シングルトン生成&左モータ回転角度取得 */
	 dgMotor_get &left_wheel = dgMotor_get::GetInstance();
	SINT i_left_wheel_enc = left_wheel.LMotorGet();

	/* rnCalculationにデータを渡す */
	rncalculation.SetCommand(i_forward, i_turn);

	/* シングルトン生成&バッテリー電圧値[V]を取得する */
	dgBattery_Balance_Amount_get &battery = dgBattery_Balance_Amount_get::GetInstance();
	SINT i_battery = battery.VoltageGet();
	/* 左右モーター出力値を得る */
	rncalculation.Update(s_angle, i_right_wheel_enc, i_left_wheel_enc, i_battery);
	/* 左右モータに回転を指示する */
	int8_t left	 = rncalculation.GetPwmLeft();
	int8_t right = rncalculation.GetPwmRight();
	motor_output.MotorOutput(left, right);
//	motor_output.MotorOutput(rncalculation.GetPwmLeft(), rncalculation.GetPwmRight());

	return FUNC_OK;
}

/* ------------------------------------------------------------------------- */
/*	関数名		:Initialize													 */
/*	機能名		:デバイス初期化												 */
/*	機能概要	:バランス走行に必要な数値をリセットする						 */
/*	引数		:無し														 */
/*	戻り値		:SINT			FUNK_OK			関数正常終了				 */
/*	作成日		:2018/07/02		田邉周哉		新規作成					 */
/*				:2018/07/12		田邉周哉		レビュー後修正				 */
/* ------------------------------------------------------------------------- */
SINT rnInverted_Control::Initialize() {
	/* シングルトン生成&ジャイロセンサ角位置[deg] */
	dgAngular_Velocity_get &gyro_sensor = dgAngular_Velocity_get::GetInstance();
	SINT i_offset = gyro_sensor.GyroGet();
	
	/* モータエンコーダをリセットする（高岡の関数待ち） */
	dgMotor_get &right_wheel = dgMotor_get::GetInstance();
	right_wheel.reset();		//仮宣言
	dgMotor_get &left_wheel = dgMotor_get::GetInstance();
	left_wheel.reset();		//仮宣言


	/* 倒立振子制御初期化 */
	rncalculation.Initialize(i_offset);

	return FUNC_OK;
}

/* ------------------------------------------------------------------------- */
/*	関数名		:SetCommand													 */
/*	機能名		:PWM設定													 */
/*	機能概要	:走行用計算に渡す値を設定する								 */
/*	引数		:SINT			forward			上記の定数が入る(前進値)	 */
/*				:SINT			turn			上記の定数が入る(旋回値)	 */
/*	戻り値		:SINT			FUNK_OK			関数正常終了				 */
/*	作成日		:2018/07/02		田邉周哉		新規作成					 */
/*				:2018/07/12		田邉周哉		レビュー後修正				 */
/* ------------------------------------------------------------------------- */
SINT rnInverted_Control::SetCommand(SINT forward, SINT turn) {
	i_forward = forward;
	i_turn = turn;

	return FUNC_OK;
}


/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
