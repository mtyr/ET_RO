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
	frLog &log = frLog::GetInstance();
	
	log.LOG(LOG_ID_ERR,"stLineUP\r\n");
	
	/* カラー情報取得クラス生成 											 */
	dgColor_Get &dgColor=dgColor_Get::GetInstance(); 
	/* しきい値情報取得クラス生成 											 */
	class raLine_Threshold_Value raLine;
	
	static const sensor_port_t
    	touch_sensor = EV3_PORT_1;
	
	log.LOG(LOG_ID_ERR,"log\r\n");
	ev3_lcd_draw_string
	("black_touch_sensor\0", 0, 0);

	while (1)
	{   /* タッチセンサーが押されている間とそうでないときで処理を分ける */
		if (ev3_touch_sensor_is_pressed(touch_sensor) == true){
			/* しきい値の更新												   */
			i_black = dgColor.ColorGet();
			break;
		}
		else{
			log.LOG(LOG_ID_ERR,"switch_wait\r\n");
		}
	}
	
	ev3_lcd_draw_string
	("white_touch_sensor\0", 0, 0);

	while (1)
	{   /* タッチセンサーが押されている間とそうでないときで処理を分ける */
		if (ev3_touch_sensor_is_pressed(touch_sensor) == true){
			/* しきい値の更新												   */
			i_white = dgColor.ColorGet();
			break;
		}
		else{
			log.LOG(LOG_ID_ERR,"switch_wait\r\n");
		}
	}

	i_gray = stLineGRAY();
	log.LOG(LOG_ID_ERR,"stLine_Set\r\n");

	raLine.raLineUP(i_black,i_white,i_gray);

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
	gray = i_white - i_black;
	gray = gray / 2;
	i_gray = gray;
	return i_gray;
}
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */