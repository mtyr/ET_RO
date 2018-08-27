/*	-----------------------------------------------------------------------	 */
/*	stLine_Threshold_Value_Set.cpp											 */
/*	ラインしきい値更新する関数												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴									日付		氏名	 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/06/29	松浦 侑矢	 */
/*	000001	仕様変更								2018/07/10	松浦 侑矢	 */
/*	000002	コード修正								2018/07/12	松浦 侑矢	 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	includeファイル															 */
/*	-----------------------------------------------------------------------	 */
#include "..\dgColor_Get\dgColor_Get.h"
#include "stLine_Threshold_Value_Set.h"
#include "..\raLine_Threshold_Value\raLine_Threshold_Value.h"
#include "..\frLog\frLog.h"
#include "ev3api.h"
#include "..\Lcd\Lcd.h"

/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	: stLine_Threshold_Value_Set::stLineUP							 */
/* 機能名	: カラー情報返答												 */
/* 機能概要	: カラー情報を返す												 */
/* 引数		: void					:なし									 */
/* 戻り値	: SINT: i_color			:しきい値	   						     */
/* 作成日	: 2018/07/10	松浦 侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
SINT stLine_Threshold_Value_Set::stLineUP(void){
	
	/*	クラス宣言---------------------------------------------------------	 */
	dgColor_Get &color =dgColor_Get::GetInstance();	/*	カラークラス		 */
	frLog &log = frLog::GetInstance();				/*	ログクラス			 */
	
	raLine_Threshold_Value &raLine =
	raLine_Threshold_Value::GetInstance();			/*	しきい値クラス		 */
	Lcd lcd;										/*	LCDクラス			 */
	
	
	/*	タッチセンサーセット	*/
	static const sensor_port_t
    	touch_sensor = EV3_PORT_1;
	
	lcd.LcdPrint("black_get");
	while (1)
	{   /* タッチセンサーが押されている間とそうでないときで処理を分ける */
		if (ev3_touch_sensor_is_pressed(touch_sensor) == true){
			/* しきい値の更新												   */
			i_black = color.ColorGet();
			log.LOG(LOG_ID_LINETRACE,"black=%d\r\n",i_black);
			break;
		}else{
			color.ColorUpdate();
			i_black = color.ColorGet();
			log.LOG(LOG_ID_LINETRACE,"black=%d\r\n",i_black);
		}
	}
	while (1)
	{   /* タッチセンサーが押されている間とそうでないときで処理を分ける */
		if (ev3_touch_sensor_is_pressed(touch_sensor) == false){
			break;
		}
	}
	
	lcd.LcdPrint("white_get");
	
	while (1)
	{   /* タッチセンサーが押されている間とそうでないときで処理を分ける */
		if (ev3_touch_sensor_is_pressed(touch_sensor) == true){
			/* しきい値の更新												   */
			i_white = color.ColorGet();
			log.LOG(LOG_ID_LINETRACE,"white=%d\r\n",i_white);
			break;
		}else{
			color.ColorUpdate();
			i_white = color.ColorGet();
			log.LOG(LOG_ID_LINETRACE,"white=%d\r\n",i_white);
		}
	}

	i_gray = stLineGRAY();

	raLine.raLineUP(i_gray);
	return FUNC_OK;
}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	: stLine_Threshold_Value_Set::stLineGRAY								 */
/* 機能名	: カラー情報返答												 */
/* 機能概要	: カラー情報を返す												 */
/* 引数		: void					:なし									 */
/* 戻り値	: SINT: i_color			:しきい値	   						     */
/* 作成日	: 2018/07/10	松浦 侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
SINT stLine_Threshold_Value_Set::stLineGRAY(void){
	SINT gray = 0;
	gray = i_white + i_black;
	gray = gray / 2;
	i_gray = gray;
	//i_gray=i_gray+10;//甲田テスト追加
	return i_gray;
}
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */