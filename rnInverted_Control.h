/*	-----------------------------------------------------------------------	 */
/*	rnInverted_Control.h													 */
/*	<EV3ライントレース>ソフトウェア開発										 */
/*	倒立制御を担当															 */
/*																			 */
/*	-----------------------------------------------------------------------	 */
/*	番号		更新履歴							日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000		新規作成							2018/07/02	田邉  周哉	 */
/*	-----------------------------------------------------------------------	 */

#ifndef RNINVERTED_CONTROL_H_
#define RNINVERTED_CONTROL_H_

#include "ev3api.h"
#include "common.h"								/* コーディング規約			 */
#include "rnCalculation_Cpp.h"					/* 走行用計算・管理			 */
#include "dgAngular_Velocity_get.h"				/* デバイス取得（ジャイロ）	 */
#include "dgBattery_Balance_Amount_get.h"		/* デバイス取得（バッテリー）*/
#include "dgMotor_get.h"						/* デバイス取得（モーター）	 */
#include "dcMotor_Output.h"						/* モーター出力				 */

class rnInverted_Control {
public:
	static const SINT LOW;
	static const SINT NORMAL;
	static const SINT HIGH;
	
	rnInverted_Control();
	SINT Initialize();
	SINT Run();
	SINT SetCommand(SINT forward, SINT turn);

private:
	SINT i_forward;								/* 前進値					 */
	SINT i_turn;								/* 旋回値					 */
	class dcMotor_Output motor_output;			/* モーター出力クラス		 */
	class rnCalculation rncalculation;			/* 走行用計算クラス			 */
};

#endif	// RNINVERTED_CONTROL_H_

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
