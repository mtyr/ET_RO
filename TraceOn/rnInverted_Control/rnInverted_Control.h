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
/* コーディング規約 */
#include "..\common\common.h"
/* デバイス取得（モーター） */
#include "..\dgMotor_get\dgMotor_get.h"
/* モーター出力 */
#include "..\dcMotor_Output\dcMotor_Output.h"


/* class宣言 */
class rnInverted_Control {
	/* public定義 */
public:
	static const SINT LOW;
	static const SINT NORMAL;
	static const SINT HIGH;
	static const SINT MLOW;
	static const SINT MHIGH;
	static const SINT ZERO;	
	
	rnInverted_Control();						/* コンストラクタ			 */
	~rnInverted_Control();						/* デストラクタ				 */
	SINT Initialize();							/* 計算値初期化クラス		 */
	SINT Run();									/* 走行実行クラス			 */
	SINT SetCommand(SINT forward, SINT turn);	/* 前進値/旋回値格納クラス	 */

	/* private定義 */
private:
	SINT i_forward;								/* 前進値					 */
	SINT i_turn;								/* 旋回値					 */
	SINT i_right;								/* 右モーター出力値			 */
	SINT i_left;								/* 左モーター出力値			 */
	class dcMotor_Output motor_output;
};

#endif	// RNINVERTED_CONTROL_H_

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
