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
#include"crStart_Preparation.h"
#include"..\stGyro_Set\stGyro_Set.h"
#include"..\stLine_Threshold_Value_Set\stLine_Threshold_Value_Set.h"
#include"..\stMotor_Initialization\stMotor_Initialization.h"
#include "..\crDriving_Order\crDriving_Order.h"
#include "..\frLog\frLog.h"
#include "..\dcTail_Motor_Output\dcTail_Motor_Output.h"

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

/*	変数宣言---------------------------------------------------------------	 */
	SINT i_moter_l = 0;							/*	左モータ遊び値			 */
	SINT i_moter_r = 0;							/*	右モーター遊び値		 */
	SINT i_moter_t = 0;							/*	尻尾モーター遊び値		 */

/*	初期化-----------------------------------------------------------------	 */

/*	クラス宣言-------------------------------------------------------------	 */	
 stGyro_Set 				 	GyroSet;		/*	ジャイロセット			 */
 stLine_Threshold_Value_Set 	LineTraceVal;	/*	ラインしきい値			 */
 crDriving_Order 			 	DriviOder;		/*	ドライビング開始		 */
 stMotor_Initialization 	 	MotorInit;		/*	モーター初期化			 */
frLog &log = frLog::GetInstance();				/*	ログ機能の追加			 */
dcTail_Motor_Output TailMotor;					/*	尻尾モーター			 */

/*	スタート準備開始-------------------------------------------------------	 */


/*	タッチセンサー設定-----------------------------------------------------	 */
ev3_lcd_draw_string	("switch_settings\0",0,0);
	log.LOG(LOG_ID_ERR,"switch_settings\r\n");
ev3_sensor_config	( EV3_PORT_1 ,TOUCH_SENSOR);

/*	カラーセンサーしきい値設定---------------------------------------------	 */
ev3_lcd_draw_string	("color_settings\0",0,0);
	log.LOG(LOG_ID_ERR,"color_settings\r\n");
LineTraceVal.stLineUP();


/*	モーター初期化---------------------------------------------------------	 */
ev3_lcd_draw_string	("motor_init\0",0,0);
log.LOG(LOG_ID_ERR,"motor_init\r\n");
MotorInit.MotorMeasurement(&i_moter_l,&i_moter_r,&i_moter_t);

/*	尻尾モーターの下す	*/
	ev3_lcd_draw_string	("tail_moter_down\0",0,0);
	log.LOG(LOG_ID_ERR,"tail_moter_down\n");
	TailMotor.TailMotorOutput(93);
/*	スタート待ち-----------------------------------------------------------	 */
ev3_lcd_draw_string	("touch\0",0,0);
	log.LOG(LOG_ID_ERR,"touch\r\n");
	
while(1){

	if(ev3_touch_sensor_is_pressed	(EV3_PORT_1) == true)	
	{
		break;
	}
}

ev3_lcd_draw_string	("release\0",0,0);
	log.LOG(LOG_ID_ERR,"release\r\n");
while(1){
	if(ev3_touch_sensor_is_pressed	(EV3_PORT_1) == false)
	{
		break;	
	}
}



/*	ジャイロセンサーセット-------------------------------------------------	 */
ev3_lcd_draw_string	("gyro_set\0",0,0);
log.LOG(LOG_ID_ERR,"gyro_set\n");
GyroSet.OffSetStart();

/*	ドライビングオーダー開始---------------------------------------------------	*/
ev3_lcd_draw_string	("Driving_start\0",0,0);
	log.LOG(LOG_ID_ERR,"Driving_start\n");
DriviOder.RunWayDecision();

}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
