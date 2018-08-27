/*	-----------------------------------------------------------------------	 */
/*	app.cpp																	 */
/*	2018_ETロボコンのメインソース											 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/25	小西 巧	 	 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	includeファイル															 */
/*	-----------------------------------------------------------------------	 */
#include "app.h"
#include "common\common.h"
#include "crStart_Preparation\crStart_Preparation.h"
#include "frLog\frLog.h"
#include "frBluetooth\frBluetooth.h"

#include "dgAngular_Velocity_Get\dgAngular_Velocity_Get.h"
#include "dgBattery_Balance_Amount_Get\dgBattery_Balance_Amount_Get.h"
#include "dgColor_Get\dgColor_Get.h"
#include "dgMotor_Get\dgMotor_Get.h"
#include "rnInverted_Control\rnInverted_Control.h"

#include <string.h>
//using namespace ev3api;


/*	-----------------------------------------------------------------------	 */
/*	メインタスク															 */
/*	-----------------------------------------------------------------------	 */
void main_task(intptr_t unused) {
	/*	変数宣言-----------------------------------------------------------	 */
		
	/*	変数初期化---------------------------------------------------------	 */
		
	/*	クラス宣言---------------------------------------------------------	 */
	crStart_Preparation StPrepara;				/*	スタート準備クラス		 */
	//frLog &log = frLog::GetInstance();			/*	ログクラス				 */
	
	/*	周期ハンドラの開始-------------------------------------------------	 */
	ev3_sta_cyc(BT_CYC);						/* bluetooth受信			 */
	//ev3_sta_cyc(DC_CYC);						/*	デバイス更新			 */
	
	StPrepara.StartPreparation();				/*	スタート準備開始		 */
	
	ext_tsk();
}

/*	-----------------------------------------------------------------------	 */
/*	デバイス周期ハンドラ													 */
/*	-----------------------------------------------------------------------	 */
void dc_cyc(intptr_t unused)
{
	/*	クラス宣言---------------------------------------------------------	 */
	dgAngular_Velocity_Get &gyro = 
	dgAngular_Velocity_Get::GetInstance();		/*	ジャイロクラス			 */
	
	dgBattery_Balance_Amount_Get &battery = 
	dgBattery_Balance_Amount_Get::GetInstance();/*	バッテリークラス		 */
	
	dgColor_Get &color = 
	dgColor_Get::GetInstance();					/*	カラークラス			 */
	
	/*	各デバイスの更新---------------------------------------------------	 */
	gyro.GyroUpdate();
	battery.batteryUpdate();
	color.ColorUpdate();
	
}

/*	-----------------------------------------------------------------------	 */
/*	Bluetoothタイマー割込み													 */
/*	-----------------------------------------------------------------------	 */
void bt_cyc(intptr_t unused)
{
	/*	変数宣言-----------------------------------------------------------	 */
	static	SCHR cBuf;							/*	受信時の比較用配列		 */
	
	/*	クラス宣言---------------------------------------------------------	 */
	 frBluetooth &bluetooth = frBluetooth::GetInstance();
	 frLog &log = frLog::GetInstance();

	/*	Bluetooth文字受信--------------------------------------------------	 */
	cBuf = bluetooth.Receive();
	
	/*	比較	*/
	if( cBuf != EOF ){

		/*	ログの出力	*/
		//log.LOG(LOG_ID_ERR,&cBuf);
		//log.LOG(LOG_ID_ERR,"\0");
		
		/*	ログのIDセット	*/
        log.SetLog(cBuf);
		cBuf=EOF;
	}
}

/*	-----------------------------------------------------------------------	 */
/*	倒立振子周期ハンドラ用関数												 */
/*	-----------------------------------------------------------------------	 */
void bla_cyc(intptr_t unused)
{
	/*	クラス宣言---------------------------------------------------------	 */
	//frLog &log = frLog::GetInstance();					/*	ログクラス	*/
	dgMotor_Get &motor=dgMotor_Get::GetInstance();/*	モータークラス	*/
	rnInverted_Control &inverted = rnInverted_Control::GetInstance();/*	倒立クラス	*/
	
	inverted.BalanceControl();

		motor.MotorUpdate();
		
		//FLOT Kyori=motor.MotorDistance();
		//log.LOG( LOG_ID_LINETRACE,"Kyori= %f\r\n",Kyori);/* Logメソッド	 */

}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
