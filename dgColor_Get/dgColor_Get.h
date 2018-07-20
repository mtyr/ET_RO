#ifndef __COLOR__
#define __COLOR__
/*	-----------------------------------------------------------------------	 */
/*	dgStatic_Color_Get.h												   	 */
/*	カラーセンサー情報取得													 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/05/15	��岡 諒太	 */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include "common.h"								/* typedef宣言等			 */
#include "ev3api.h"								/* ev3apiライブラリー		 */

/* クラス宣言--------------------------------------------------------------- */
class dgColor_Get{

public:
	/* publicメソッド */
	static dgColor_Get& GetInstance(void);		/* 実体作成メソッド			 */
	uint8_t ColorGet();							/* 角位置情報引き渡しメソッド*/
	void ColorUpdate(void);						/* 角位置情報更新			 */
private:
	/* privateメソッド------------------------------------------------------ */
	dgColor_Get();								/* コンストラクタ			 */
	~dgColor_Get();								/* デストラクタ				 */
	/* シングルトンに必要な奴 */
	dgColor_Get(const dgColor_Get &x) { };
	dgColor_Get&operator=(const dgColor_Get &) { return *this; };
	/* private変数---------------------------------------------------------- */
	uint8_t i_color_info;							/* 取得した色情報		 */
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif
