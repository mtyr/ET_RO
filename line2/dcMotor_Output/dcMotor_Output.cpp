/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														     */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	:dcMotor_Output 				　　　　　　					 */
/* 機能名	:モーター走行　　　　　 										 */
/* 機能概要	:モーター出力   												 */
/* 引数		:SINT getPwmLeft		左回転数	     						 */
/*　　　　　:SINT getPwmRight		右回転数	     						 */
/* 戻り値	:なし					                                         */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/03	廖  振勛	 */
/*	000001	関数名修正								2018/07/04	廖  振勛	 */
/*	000002	コード修正								2018/07/09	廖  振勛	 */
/*	000003	コード修正								2018/07/20	廖  振勛	 */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */

#include "dcMotor_Output.h"
#include "..\frLog\frLog.h"

dcMotor_Output::dcMotor_Output(){
	ev3_motor_config(EV3_PORT_B,LARGE_MOTOR );                        //ポート設定
	ev3_motor_config(EV3_PORT_C,LARGE_MOTOR );						   //ポート設定
}

void dcMotor_Output::MotorOutput(SINT getPwmLeft,SINT getPwmRight) {   //モーター出力

	frLog &log = frLog::GetInstance();
	log.LOG(LOG_ID_ERR,"dcMotor_Output_start\r\n");

	/* Lモーターを回す */
	ev3_motor_set_power(EV3_PORT_C,getPwmLeft);
	log.LOG(LOG_ID_ERR,"L_motor_Out\r\n");
	/* Rモーターを回す */
    ev3_motor_set_power(EV3_PORT_B,getPwmRight);
	log.LOG(LOG_ID_ERR,"R_motor_Out\r\n");
}


/* ------------------------------------------------------------------------- */
