/* ------------------------------------------------------------------------- */
/* rnLine_Trace.cpp															 */
/* ETロボコン開発															 */
/* ライントレース機能です。													 */
/*																			 */
/* ------------------------------------------------------------------------- */
/* 番号		更新履歴							日付			氏名		 */
/* ------------------------------------------------------------------------- */
/* 000000	新規作成							2018/07/02		甲田  啓朗	 */
/* 000001	関数ヘッダの記入					2018/07/03		甲田  啓朗	 */
/* 000002	Color_Runningメソッドの追加作成		2018/07/10		甲田  啓朗	 */
/* 000003	コーディングレビュー修正点の修正	2018/07/12		甲田  啓朗	 */
/* 000004	コーディングレビュー修正点の修正	2018/07/13		甲田  啓朗	 */
/* 000005	Cygwinエラー箇所の修正				2018/07/18		甲田  啓朗	 */
/* 000006	BOOL→SINTに変更修正				2018/07/20		甲田  啓朗	 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* include ファイル															 */
/* ------------------------------------------------------------------------- */
#include "..\common\common.h"
#include "rnLine_Trace.h"
#include "..\raLine_Threshold_Value\raLine_Threshold_Value.h"
#include "..\rnInverted_Control\rnInverted_Control.h"

/* ------------------------------------------------------------------------- */
/* 関数名	:rnLine_Trace													 */
/* 機能名	:コンストラクタ													 */
/* 機能概要	:初期化															 */
/* 引数		:raLine_Threshold_Value*	:line_threshold_value	:参照渡し	 */
/* 戻り値	:なし															 */
/* 作成日	:2018/07/02		甲田  啓朗	新規作成							 */
/* ------------------------------------------------------------------------- */
rnLine_Trace::rnLine_Trace(){
	/* バランス走行に必要なものをリセットするか決める変数					 */
	i_initialized = FALSE;
}

/* ------------------------------------------------------------------------- */
/* 関数名	:LineTracing													 */
/* 機能名	:ライントレース													 */
/* 機能概要	:ライントレース制御。											 */
/* 引数		:なし															 */
/* 戻り値	:SINT	:FUNC_OK	:正常終了									 */
/* 作成日	:2018/07/02		甲田  啓朗	新規作成							 */
/* ------------------------------------------------------------------------- */
SINT rnLine_Trace::LineTracing() {



	/* 倒立制御クラスの生成 */
	class rnInverted_Control myrnInverted_Control;

	/* ラインしきい値クラス  GetInstance */
	static raLine_Threshold_Value &ColorGet 
					= raLine_Threshold_Value::GetInstance();
	i_color = ColorGet.raLineSet();				/* i_colorにラインの色を格納 */

	/* 倒立走行に必要なものをリセットするかのチェック */
	if (i_initialized == FALSE) {
		myrnInverted_Control.Initialize();
		i_initialized = TRUE;
	}


	i_color = TS_BRACK;	/* ループに入る為に初期設定でTS_BRACK(黒色)を設定	 */
	/* ラインの色が灰色になるまでループ */
	while (TS_GRAY != i_color)
	{

	/* ラインしきい値Classのしきい値セットMethodを呼ぶ */
	/* 現在のラインの色を取得 */
	i_color = ColorGet.raLineSet();

	/* 走行体の向きを決める */
	i_direction = ColorDirection(i_color);

	/* 倒立制御ClassのSetCommandMethodを呼ぶ */
	/* PWM値を設定する */
	myrnInverted_Control.SetCommand(rnInverted_Control::LOW, i_direction);

	/* 倒立走行を行う */
	myrnInverted_Control.Run();

	}

	return FUNC_OK;									/* 灰色が来たことを報告	 */
}


/* ------------------------------------------------------------------------- */
/* 関数名	:ColorDirection													 */
/* 機能名	:色に合った走行向きを決める										 */
/* 機能概要	:ラインの色を判断して走行向きを戻り値として返す					 */
/* 引数		:SINT	:i_color	:現在のラインの色							 */
/* 戻り値	:SINT:rnInverted_Control::LOW	:黒色 or 灰色が来た時(LOW = 30)	 */
/*       	:	 :-rnInverted_Control::LOW	:白色が来た時(-LOW = -30)		 */
/* 作成日	:2018/07/02		甲田  啓朗	新規作成							 */
/* ------------------------------------------------------------------------- */
SINT rnLine_Trace::ColorDirection(SINT i_color) {

	/* 現在のラインの色チェック */
	if (TS_BRACK == i_color) {								/* ライン黒色	 */
			return rnInverted_Control::LOW;
		}
		else if (TS_WHITE == i_color)						/* ライン白色	 */
		{
			return -rnInverted_Control::LOW;
		}
		else if (TS_GRAY == i_color)						/* ライン灰色	 */
		{
			return rnInverted_Control::LOW;
		}
		else
		{
			return FUNC_ERR;								/* 関数異常終了	 */
		}
}

/* ------------------------------------------------------------------------- */
/* 				Copyright HAL College of Technology & Design				 */
/* ------------------------------------------------------------------------- */

