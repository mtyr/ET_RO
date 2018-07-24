/* ------------------------------------------------------------------------- */
/*	rnCalculation_Cpp.h                                                      */
/*	<EV3ライントレース>ソフトウェア開発                                      */
/*  走行用計算管理クラス                                                     */
/*	倒立制御クラスからの指示で走行用計算を管理する                           */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	番号		更新履歴							日付		氏名		 */
/*	-----------------------------------------------------------------------  */
/*	000000		新規作成							2018/07/11	田邉  周哉	 */
/* ------------------------------------------------------------------------- */

#ifndef EV3_UNIT_CALCULATION_CPP_H_
#define EV3_UNIT_CALCULATION_CPP_H_

#include "ev3api.h"
#include "..\common\common.h"								/* コーディング規約          */

class rnCalculation {
public:
	rnCalculation();

	void Initialize(SINT offset);
    void Update(SINT angle, SINT rwEnc, SINT lwEnc, SINT battery);
    void SetCommand(SINT forward, SINT turn);
    int8_t GetPwmRight();
	int8_t GetPwmLeft();

private:
	SINT CancelBacklash(int8_t pwm, SINT enc);

    SINT i_forward;
    SINT i_turn;
    SINT i_offset;
	int8_t i_right_pwm;
	int8_t i_left_pwm;
};

#endif  // EV3_UNIT_CALCULATION_CPP_H_

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
