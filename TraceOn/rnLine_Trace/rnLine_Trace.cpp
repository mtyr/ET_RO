/* ------------------------------------------------------------------------- */
/* include ファイル															 */
/* ------------------------------------------------------------------------- */
#include "ev3api.h"
#include "..\common\common.h"
#include "rnLine_Trace.h"
#include "..\rnInverted_Control\rnInverted_Control.h"

/* ------------------------------------------------------------------------- */
/* コンストラクタ															 */
/* ------------------------------------------------------------------------- */
rnLine_Trace::rnLine_Trace(){
	/* バランス走行に必要なものをリセットするか決める変数					 */
	i_initialized = FALSE;
	
}

/* ------------------------------------------------------------------------- */
/* デストラクタ																 */
/* ------------------------------------------------------------------------- */
rnLine_Trace::~rnLine_Trace(){
	/* スケルトン */
}

/* ------------------------------------------------------------------------- */
/* ライントレース															 */
/* ------------------------------------------------------------------------- */
SINT rnLine_Trace::LineTracing() {

	/* 倒立制御クラスの生成 */
	class rnInverted_Control myrnInverted_Control;

	/* 倒立走行に必要なものをリセットするかのチェック */
	if (i_initialized == FALSE) {
		myrnInverted_Control.Initialize();
		i_initialized = TRUE;
	}

	/* 無限ループ */
	while (1)
	{
		/* 倒立制御ClassのSetCommandMethodを呼ぶ */
		/* PWM値を設定する */
		myrnInverted_Control.SetCommand(rnInverted_Control::LOW, rnInverted_Control::LOW);

		/* 倒立走行を行う */
		myrnInverted_Control.Run();

		/* 4秒間制御を受け付けない */
		tslp_tsk(4);
	}
}

/* ------------------------------------------------------------------------- */
/* 				Copyright HAL College of Technology & Design				 */
/* ------------------------------------------------------------------------- */

