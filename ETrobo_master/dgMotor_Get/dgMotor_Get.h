#ifndef __MOTOR__
#define __MOTOR__
/*	-----------------------------------------------------------------------	 */
/*	dgStatic_Color_Get.h												   	 */
/*	カラーセンサー情報取得                                                     */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		   */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/05/15	髙岡 諒太	  */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include "..\common\common.h"					/* typedef宣言等			 */
#include "ev3api.h"								/* ev3apiライブラリー		 */

#define pi				(                 3.14 )	/*  円周率				 */
#define f_wheel_diameter(                 	10 )	/*  車輪直径			 */

/* クラス宣言--------------------------------------------------------------- */
class dgMotor_Get{

public:
	/* publicメソッド */

	static dgMotor_Get& GetInstance(void);		/* 実体作成メソッド			 */
	uint16_t RMotorGet();						/* 右角位置情報引き渡しメソッド	 */
	uint16_t LMotorGet();						/* 左角位置情報引き渡しメソッド	 */
	void MotorUpdate(void);						/* 角位置更新メソッド		 */
	void dgMortor_OffSet();						/* モーターオフセット */
	SINT MotorDistance();						/* モーターの走行距離計算メソッド */
private:
	/* privateメソッド------------------------------------------------------ */
	dgMotor_Get();								/* コンストラクタ			 */
	~dgMotor_Get();								/* デストラクタ				 */
	/* シングルトンに必要な奴 */
	dgMotor_Get(const dgMotor_Get &x) { };
	dgMotor_Get&operator=(const dgMotor_Get &) { return *this; };


	/* private変数---------------------------------------------------------- */
	uint16_t i_rmotor_info;							/* 取得した右角位置情報	 */
	uint16_t i_lmotor_info;							/* 取得した左角位置情報 */
	SINT i_rmotor_Rotation;							/* 右モータ回転数 */
	SINT i_lmotor_Rotation;							/* 左モータ回転数 */
	FLOT f_wheel_diameter=10;						/* 車輪直径（固定値） */
	FLOT f_rmotor_distance;							/* 右モータ走行距離 */
	FLOT f_lmotor_distance;							/* 左モータ走行距離 */
	FLOT f_motor_distance;							/* 平均走行距離 */
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif