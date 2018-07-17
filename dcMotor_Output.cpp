#include "BalancingWalker.h"
#include "BalancerCpp.h"
#include "dcMotor_Output.h"
#include "app.h"


/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														     */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	:dcMotor_Output 				　　　　　　					 */
/* 機能名	:モーター走行　　　　　 										 */
/* 機能概要	:モーター出力   												 */
/* 引数		:void			     											 */
/* 戻り値	:なし					                                         */
/* 作成日	: 2018/07/03	廖  振勛			新規作成				     */
/* 更新   	: 2018/07/04	廖  振勛			関数名修正				     */
/* 更新   	: 2018/07/09	廖  振勛			コード修正				     */
/* ------------------------------------------------------------------------- */

static const motor_port_t
    M_motor      = EV3_PORT_D,
    L_motor      = EV3_PORT_A;

void dcMotor_Output::MotorOutput(int8_t getPwmLeft,int8_t getPwmRight) {   //モーター出力

	/* Lモーターを回す */
	ev3_motor_set_power(L_motor,getPwmLeft);
	/* Mモーターを回す */
    ev3_motor_set_power(M_motor,getPwmRight);
}


/* ------------------------------------------------------------------------- */

