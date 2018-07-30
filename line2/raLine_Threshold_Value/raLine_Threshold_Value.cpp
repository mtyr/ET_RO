/*	-----------------------------------------------------------------------	 */
/*	raLine_Threshold_Value.cpp												 */
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
#include "raLine_Threshold_Value.h"
#include "..\dgColor_Get\dgColor_Get.h"
#include "..\frLog\frLog.h"

/* ------------------------------------------------------------------------- */
/* 関数名	: raLine_Threshold_Value::raLine_Threshold_Value				 */
/* 機能名	: しきい値取得：コンストラクタ									 */
/* 機能概要	: 初回インスタンス生成時にコールされます						 */
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* 作成日	: 2018/07/9			松浦 侑矢		新規作成					 */
/* ------------------------------------------------------------------------- */
raLine_Threshold_Value::raLine_Threshold_Value()
{
}
/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* 関数名	: raLine_Threshold_Value::raLineSet								 */
/* 機能名	: 現在カラー値返答												 */
/* 機能概要	: 現在カラー値を返す											 */
/* 引数		: void					:なし									 */
/* 戻り値	: SINT: FUNC_ERR		:関数異常終了							 */
/* 作成日	: 2018/07/10	松浦 侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
SINT raLine_Threshold_Value::raLineSet(void)
{
	frLog &log = frLog::GetInstance();
	log.LOG(LOG_ID_ERR,"raLine\r\n");
	log.LOG(LOG_ID_ERR,"WHITE=%d\r\n",i_white);
	log.LOG(LOG_ID_ERR,"BLACK=%d\r\n",i_black);
	log.LOG(LOG_ID_ERR,"GRAY=%d\r\n",i_gray);
	/* 現在カラー値の更新													 */
	i_current_color = raLineGet(i_current_color);
	log.LOG(LOG_ID_ERR,"currnt=%d\r\n",i_current_color);
	/* 現在カラー値の比較													 */
	if(i_current_color < i_gray)
	{
		
		log.LOG(LOG_ID_ERR,"BLACK=%d\r\n",i_black);
		return TS_BLACK;
	}
	else if(i_current_color > i_gray )
	{
		log.LOG(LOG_ID_ERR,"WHITE=%d\r\n",i_white);
		
		return TS_WHITE;
	}
	else
	{
		log.LOG(LOG_ID_ERR,"ERR%d\r\n");
		return FUNC_ERR;
		
	}
	/*i_gray1=i_gray+10;
	i_gray2=i_gray-10;
	
	if (i_current_color <= i_white&&i_gray1 < i_current_color){
		log.LOG(LOG_ID_ERR,"WHITE\r\n");
		return TS_WHITE;
	}
	else if(i_current_color > i_white)
	{
		log.LOG(LOG_ID_ERR,"WHITE\r\n");
		return TS_WHITE;
	}
	else if (i_current_color >= i_black&&i_current_color < i_gray2){
		log.LOG(LOG_ID_ERR,"BRACK\r\n");
		return TS_BRACK;
	}
	else if(i_current_color < i_black)
	{
		log.LOG(LOG_ID_ERR,"BRACK\r\n");
		return TS_BRACK;
	}
	else if (i_gray1 >= i_current_color &&i_gray2 <= i_current_color){
		log.LOG(LOG_ID_ERR,"GRAY\r\n");
		return TS_GRAY;
	}
	else
	{
		return FUNC_ERR;
	}
	*/
}

/* ------------------------------------------------------------------------- */
/* 関数名	: raLine_Threshold_Value::raLineUP								 */
/* 機能名	:																 */
/* 機能概要	:																 */
/* 引数		: void					:なし									 */
/* 戻り値	: SINT: FUNC_ERR		:関数異常終了							 */
/* 作成日	: 2018/07/10	松浦 侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
SINT raLine_Threshold_Value::raLineUP(SINT black, SINT white, SINT gray)
{
	i_black = black;
	i_gray  = gray;
	i_white = white;

	return FUNC_OK;
}
/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* 関数名	: raLine_Threshold_Value::raLineGet							     */
/* 機能名	: ラインしきい値：現在カラー値の更新							 */
/* 機能概要	: 現在カラー値の更新											 */
/* 引数		: SINT: i_current_color		:現在カラー値更新前					 */
/* 戻り値	: SINT: i_current_color		:現在カラー値更新後					 */
/* 作成日	: 2018/07/10 	松浦 侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
SINT raLine_Threshold_Value::raLineGet(SINT i_current_color){
	/* カラー情報取得クラス生成 											 */
	dgColor_Get &dgColor = dgColor_Get::GetInstance(); 
	
	/* ラインしきい値取得からしきい値を取得									 */
	i_current_color = dgColor.ColorGet();

	return i_current_color;
}
//UPでライントレースに値を渡す。

/* ------------------------------------------------------------------------- */
/* 関数名	: raLine_Threshold_Value::GetInstance							 */
/* 機能名	: カラー取得:クラス実体の作成、アドレス渡し						 */
/* 機能概要	: 呼ばれた関数にクラスのアドレスを返却します					 */
/* 引数		: void			: なし											 */
/* 戻り値	: raLine_Threshold_Value&			: obj						 */
/* 作成日	: 2018/07/2		松浦 侑矢 		新規作成						 */
/* ------------------------------------------------------------------------- */
raLine_Threshold_Value& raLine_Threshold_Value::GetInstance(void)
{
	static raLine_Threshold_Value obj;			/* クラス実体作成(最初のみ)	 */
	return obj;									/* クラスアドレス返却		 */
}
/* ------------------------------------------------------------------------- */
/* 関数名	: raLine_Threshold_Value::~raLine_Threshold_Value			   	 */
/* 機能名	: しきい値取得：デストラクタ									 */
/* 機能概要	: staticクラスの為、コールされることは無い						 */
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* 作成日	: 2018/07/9		松浦 侑矢		新規作成						 */
/* ------------------------------------------------------------------------- */
raLine_Threshold_Value::~raLine_Threshold_Value()
{
}
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
