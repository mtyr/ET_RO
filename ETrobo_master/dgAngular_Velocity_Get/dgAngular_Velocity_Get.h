#ifndef __GYRO__
#define __GYRO__
/*	-----------------------------------------------------------------------	 */
/*	dgAngular_Velocity_Get.h												 */
/*	カラーセンサー情報取得													 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/05/15	髙岡 諒太	 */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include "..\common\common.h"								/* typedef宣言等			 */
#include "ev3api.h"								/* ev3apiライブラリー		 */
/* クラス宣言--------------------------------------------------------------- */
class dgAngular_Velocity_Get{

public:
	/* publicメソッド */
	static dgAngular_Velocity_Get& GetInstance(void);/* 実体作成メソッド	 */
	SINT GyroGet();								/* 色情報引き渡しメソッド	 */
	void GyroUpdate(void);						/* 角速度更新メソッド		 */
	SINT OffSet(void);							/* オフセットメソッド		 */
private:
	/* privateメソッド------------------------------------------------------ */
	dgAngular_Velocity_Get();						/* コンストラクタ		 */
	~dgAngular_Velocity_Get();						/* デストラクタ			 */
	/* シングルトンに必要な奴 */
	dgAngular_Velocity_Get(const dgAngular_Velocity_Get &x) { };
	dgAngular_Velocity_Get&operator=(const dgAngular_Velocity_Get &) { return *this; };


	/* private変数---------------------------------------------------------- */
	SINT i_gyro_info;							/* 取得した角速度情報	 */
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif