/* ------------------------------------------------------------------------- */
/*	rnInverted_Control.cpp													 */
/*	<EV3ライントレース>ソフトウェア開発										 */
/*	倒立制御クラス															 */
/*	倒立制御を担当。走行用計算クラスに計算指示を送り						 */
/*	戻り値をモーター出力に送る												 */
/*																			 */
/*	-----------------------------------------------------------------------	 */
/*	番号		更新履歴							日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	005000		新規作成							2018/07/02	田邉  周哉	 */
/*	005001		レビュー後修正						2018/07/12	田邉  周哉	 */
/*	005002		シングルトン修正					2018/07/24	田邉  周哉	 */
/*	005003		ライントレースだけ用に改変			2018/07/25	田邉  周哉	 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* includeファイル															 */
/* ------------------------------------------------------------------------- */
#include "rnInverted_Control.h"

/* ------------------------------------------------------------------------- */
/* 定数宣言																	 */
/* ------------------------------------------------------------------------- */
const SINT rnInverted_Control::ZERO = 0;		/* 0						 */
const SINT rnInverted_Control::LOW = 30;		/* 低速						 */
const SINT rnInverted_Control::NORMAL = 50;		/* 通常						 */
const SINT rnInverted_Control::HIGH = 70;		/* 高速						 */
const SINT rnInverted_Control::MLOW = 10;		/* ライントレース用低速		 */
const SINT rnInverted_Control::MHIGH = 20;		/* ライントレース用高速		 */


/* ------------------------------------------------------------------------- */
/*	関数名		:rnInverted_Control											 */
/*	機能名		:コンストラクタ												 */
/*	機能概要	:変数定義とシングルトン定義を行う							 */
/*	引数		:無し														 */
/*	戻り値		:無し														 */
/*	作成日		:2018/07/02		田邉周哉		新規作成					 */
/*				:2018/07/12		田邉周哉		レビュー後修正				 */
/* ------------------------------------------------------------------------- */
rnInverted_Control::rnInverted_Control(){
	i_forward = LOW;							/* 前進値					 */
	i_turn = LOW;								/* 旋回値					 */
}

/* ------------------------------------------------------------------------- */
/* デストラクタ 															 */
/* ------------------------------------------------------------------------- */
rnInverted_Control::~rnInverted_Control(){
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
	/* 出力値判定 ---------------------------------------------------------- */
	/* 黒検知時(反時計周り) */
	if(i_turn == LOW){
		i_right = HIGH;
		i_left = LOW;
		motor_output.MotorOutput(i_left, i_right);
	}
	/* 白検知時(時計回り) */
	else if(i_turn == -LOW ){
		i_right = LOW;
		i_left = HIGH;
		motor_output.MotorOutput(i_left, i_right);
	}
	/* 灰検知時(停止)(仮実装。使うかどうかは任せます) */
	else {
		motor_output.MotorOutput(ZERO, ZERO);
	}
	
	/* 出力値check(LCD表示) */
	SCHR c_motor_str[30];
	sprintf(c_motor_str,"右:%d    左:%d    ",i_right,i_left);
	ev3_lcd_draw_string(c_motor_str,10,30);
		
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
/*				:2018/07/26		田邉周哉		ライントレースだけ用に改変	 */
/* ------------------------------------------------------------------------- */
SINT rnInverted_Control::Initialize() {
	/* モータエンコーダをリセットする */
	dgMotor_Get &motor_reset = dgMotor_Get::GetInstance();
	motor_reset.dgMortor_OffSet();

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
