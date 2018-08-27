/*	-----------------------------------------------------------------------	 */
/*	crStart_Preparation.cpp													 */
/*	スタート準備クラス														 */
/*	スタート準備に必要なクラス												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴									日付		氏名	 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成									2018/07/02	小西 巧  */
/*	000001	文字コードと改行コードの変更				2018/07/20	小西 巧	 */
/*	-----------------------------------------------------------------------	 */

/*	----------------------------------------------------------------------	 */
/*	includeファイル														 	 */
/*	----------------------------------------------------------------------	 */
#include <string.h>
#include "crStart_Preparation.h"
#include "..\stGyro_Set\stGyro_Set.h"
#include "..\stLine_Threshold_Value_Set\stLine_Threshold_Value_Set.h"
#include "..\stMotor_Initialization\stMotor_Initialization.h"
#include "..\crDriving_Order\crDriving_Order.h"
#include "..\frLog\frLog.h"
#include "..\dcTail_Motor_Output\dcTail_Motor_Output.h"
#include "..\Lcd\Lcd.h"
#include "..\frBluetooth\frBluetooth.h"
#include "..\rnInverted_Control\rnInverted_Control.h"
#include "ev3api.h"

/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* 関数名	:fcrStart_Preparation::crStart_Preparation						 */
/* 機能名	: スタート準備：コンストラクタ									 */
/* 機能概要	:特になし														 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/02	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
crStart_Preparation::crStart_Preparation()
{

}

/* ------------------------------------------------------------------------- */
/* 関数名	:fcrStart_Preparation::~crStart_Preparation						 */
/* 機能名	: スタート準備：デストラクタ									 */
/* 機能概要	:特に処理がない													 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/02	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
crStart_Preparation::~crStart_Preparation()
{

}

/* ------------------------------------------------------------------------- */
/* 関数名	:crStart_Preparation::StartPreparation							 */
/* 機能名	: スタート準備：スタート準備開始								 */
/* 機能概要	:スタートする際に必要な設定を開始								 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/02	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
void crStart_Preparation::StartPreparation(void)
{

	/*	変数宣言-----------------------------------------------------------	 */
	//SINT i_moter_l = 0;							/*	左モータ遊び値			 */
	//SINT i_moter_r = 0;							/*	右モーター遊び値		 */
	//SINT i_moter_t = 0;							/*	尻尾モーター遊び値		 */
	
	/*	クラス宣言---------------------------------------------------------	 */
	stGyro_Set 				 	GyroSet;		/*	ジャイロセット			 */
	stLine_Threshold_Value_Set 	LineTraceVal;	/*	ラインしきい値			 */
	crDriving_Order 			DriviOder;		/*	ドライビング開始		 */
	//stMotor_Initialization 	 	MotorInit;		/*	モーター初期化			 */
	dcTail_Motor_Output 		TailMotor;		/*	尻尾モーター			 */
	Lcd 						lcd;			/*	LCDクラス	*/
	frLog &log = frLog::GetInstance();			/*	ログ機能の追加			 */
	frBluetooth &bluetooth=frBluetooth::GetInstance();/* bluetoothクラス	 */
	rnInverted_Control &invert=rnInverted_Control::GetInstance();/*	倒立クラス	*/
	
	/*	スタート準備開始-------------------------------------------------------	 */


	/*	タッチセンサー設定-----------------------------------------------------	 */
	lcd.LcdPrint("switch_set");
	ev3_sensor_config	( EV3_PORT_1 ,TOUCH_SENSOR);

	/*	カラーセンサーしきい値設定---------------------------------------------	 */
	lcd.LcdPrint("color_set");
	LineTraceVal.stLineUP();


	/*	モーター初期化---------------------------------------------------------	 */
	lcd.LcdPrint("motor_init_not");
	//MotorInit.MotorMeasurement(&i_moter_l,&i_moter_r,&i_moter_t);
	
	/*	スタート待ち-----------------------------------------------------------	 */
	lcd.LcdPrint("touch");
	log.LOG(LOG_ID_ERR,"touch\r\n");
	
	while(1){

		if( ( ev3_touch_sensor_is_pressed	(EV3_PORT_1) == true ) || 
			( bluetooth.Receive() == '1' ) )	
		
		{
			TailMotor.TailStart(TAIL_DOWN);		/*	尻尾モーターの下す		 */
			break;
		}
	}
	
	lcd.LcdPrint("release");
	log.LOG(LOG_ID_ERR,"release\r\n");
	
	while(1){
		if( ( ev3_touch_sensor_is_pressed	(EV3_PORT_1) == false ) || 
			( bluetooth.Receive() == '1' ) )
		
		{
			/*	尻尾もたーを上げる	*/
			TailMotor.TailStart(TAIL_UP);
			break;	
		}
	}
	
	/*	ドライビング開始---------------------------------------------------	 */
	invert.BalanceInit();
	ev3_sta_cyc(BLA_CYC);
	DriviOder.RunWayDecision();
}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
