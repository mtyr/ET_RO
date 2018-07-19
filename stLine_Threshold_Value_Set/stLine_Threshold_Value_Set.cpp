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
//#include "ev3api.h"
/*	-----------------------------------------------------------------------	 */
/*	変数宣言と初期化														 */
/*	-----------------------------------------------------------------------	 */
SINT i_color = 0;										 /* しきい値確保変数 */
/*	-----------------------------------------------------------------------	 */
/*　カラー情報取得クラス宣言												 */
/*	-----------------------------------------------------------------------	 */
dgColor_Get &dgColor=dgColor_Get::GetInstance(); /* カラー情報取得クラス生成 */
/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	: stLine_Threshold_Value_Set::UP								 */
/* 機能名	: カラー情報返答												 */
/* 機能概要	: カラー情報を返す												 */
/* 引数		: void					:なし									 */
/* 戻り値	: SINT: i_color			:しきい値	   						     */
/* 作成日	: 2018/07/10	松浦　侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
SINT stLine_Threshold_Value_Set::UP(void){

	/* しきい値の更新														 */
	i_color = dgColor.ColorGet();

	/* しきい値の返答														 */
	return i_color;

}


/* ------------------------------------------------------------------------- */
/* 関数名	: stLine_Threshold_Value_Set::Get								 */
/* 機能名	: しきい値設定													 */
/* 機能概要	: ラインしきい値にしきい値を設定する							 */
/* 引数		: SINT i_color			:しきい値								 */
/* 戻り値	: void					:なし		   						     */
/* 作成日	: 2018/07/10	松浦　侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
void stLine_Threshold_Value_Set::Get(SINT){
	//ev3_lcd_draw_string("黒色のラインに置いてください。\0", 0, 0);
	/* しきい値の更新														 */
	i_color = dgColor.ColorGet();

}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
