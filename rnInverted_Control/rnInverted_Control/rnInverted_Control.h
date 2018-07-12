/*	-----------------------------------------------------------------------  */
/*	rnInverted_Control.h                                                     */
/*	<EV3ライントレース>ソフトウェア開発                                      */
/*	倒立制御を担当                                                           */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	番号		更新履歴							日付		氏名		 */
/*	-----------------------------------------------------------------------  */
/*	000000		新規作成							2018/07/02	田邉  周哉	 */
/*	-----------------------------------------------------------------------  */

#ifndef RNINVERTED_CONTROL_H_
#define RNINVERTED_CONTROL_H_

#include "common.h"								/* コーディング規約          */
#include "rnCalculation.h"						/* 計算指示                  */
#include "dgStatic_Angular_Velocity_Get.h"		/* デバイス取得（ジャイロ）  */
#include "dgStatic_Battery_Balance_Amount_get.h"/* デバイス取得（バッテリー）*/
#include "dgStatic_Motor_get.h"		            /* デバイス取得（モーター）　*/

class rnInverted_Control {
public:
	static const SINT LOW;
	static const SINT NORMAL;
	static const SINT HIGH;

	rnInverted_Control(const dgStattic_Angular_Velocity_get* static_anglar_velocity_get,
					   dgStatic_Motor_get* static_motor_get_left,
					   dgStatic_Motor_get* static_motor_get_right,
					   rnCalculation* calculation);

	void Initialize();
	void Run();
	void SetCommand(SINT forward, SINT turn);

private:
	const dgStattic_Angular_Velocity_get* gyro_sensor;
	dgStatic_Motor_get* left_wheel;
	dgStatic_Motor_get* right_wheel;
	rnCalculation* rn_calculation;
	SINT i_forward;
	SINT i_turn;
};

#endif  // RNINVERTED_CONTROL_H_

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
