#ifndef __BATTERY__
#define __BATTERY__
/*	-----------------------------------------------------------------------	 */
/*	dgStatic_Color_Get.h												   	 */
/*	カラーセンサー情報取得													 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/05/15	髙岡 諒太	 */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include "common.h"								/* typedef宣言等			 */
#include "ev3api.h"								/* ev3apiライブラリー		 */
/* クラス宣言--------------------------------------------------------------- */
class dgBattery_Balance_Amount_Get{

public:
	/* publicメソッド */
	static dgBattery_Balance_Amount_Get& GetInstance(void);	/* 実体作成メソッド		 */
	SINT batteryGet();							/* 電圧情報引き渡しメソッド	 */
	void batteryUpdate(void);
private:
	/* privateメソッド------------------------------------------------------ */
	dgBattery_Balance_Amount_Get();				/* コンストラクタ			 */
	~dgBattery_Balance_Amount_Get();			/* デストラクタ				 */
	/* シングルトンに必要な奴 */
	dgBattery_Balance_Amount_Get(const dgBattery_Balance_Amount_Get &x) { };
	dgBattery_Balance_Amount_Get&operator=(const dgBattery_Balance_Amount_Get &) { return *this; };

	/* private変数---------------------------------------------------------- */
	uint8_t i_battery;							/* 取得した色情報			 */
};
#endif