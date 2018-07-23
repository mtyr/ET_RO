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
#include "dgColor_Get.h"
#include "stLine_Threshold_Value_Set.h"
#include "raLine_Threshold_Value.h"
#include "ev3api.h"
/*	-----------------------------------------------------------------------	 */
/*	変数宣言と初期化														 */
/*	-----------------------------------------------------------------------	 */
SINT i_color = 0;										 /* しきい値確保変数 */
/*	-----------------------------------------------------------------------	 */
/*　カラー情報取得クラス宣言												 */
/*	-----------------------------------------------------------------------	 */
dgColor_Get &dgColor=dgColor_Get::GetInstance(); /* カラー情報取得クラス生成 */
class raLine_Threshold_Value raLine;
/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	: stLine_Threshold_Value_Set::UP								 */
/* 機能名	: カラー情報返答												 */
/* 機能概要	: カラー情報を返す												 */
/* 引数		: void					:なし									 */
/* 戻り値	: SINT: i_color			:しきい値	   						     */
/* 作成日	: 2018/07/10	松浦 侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
SINT stLine_Threshold_Value_Set::stLineUP(void){

	ev3_lcd_draw_string
	("黒色のラインに置きタッチセンサーを押してください。\0", 0, 0);

	while (1)
	{   /* タッチセンサーが押されている間とそうでないときで処理を分ける */
		if (ev3_touch_sensor_is_pressed(touch_sensor) == true){
			/* しきい値の更新												 */
			i_black = dgColor.ColorGet();
		}
		else{
			ev3_lcd_draw_string
			("黒色のラインに置きタッチセンサーを押してください。\0", 0, 0);
		}
	}
	
	ev3_lcd_draw_string
	("白色のラインに置きタッチセンサーを押してください。\0", 0, 0);

	while (1)
	{   /* タッチセンサーが押されている間とそうでないときで処理を分ける */
		if (ev3_touch_sensor_is_pressed(touch_sensor) == true){
			/* しきい値の更新												 */
			i_white = dgColor.ColorGet();
		}
		else{
			ev3_lcd_draw_string
			("白色のラインに置きタッチセンサーを押してください。\0", 0, 0);
		}
	}

	i_gray = stLine_Threshold_Value_Set::stLineGRAY();
	ev3_lcd_draw_string("しきい値設定完了しました。\0", 0, 0);

	raLine.raLineUP(i_black,i_white,i_gray);

	return FUNC_OK;
}


/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	: stLine_Threshold_Value_Set::GRAY								 */
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
