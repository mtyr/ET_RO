#include "app.h"
#include "common\common.h"
#include "crStart_Preparation\crStart_Preparation.h"
#include "frLog\frLog.h"
#include "frBluetooth\frBluetooth.h"

#include "dgAngular_Velocity_Get\dgAngular_Velocity_Get.h"
#include "dgBattery_Balance_Amount_Get\dgBattery_Balance_Amount_Get.h"
#include "dgColor_Get\dgColor_Get.h"
#include "dgMotor_Get\dgMotor_Get.h"

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
	sta_cyc(BT_CYC);							/* bluetooth受信			 */
	sta_cyc(DC_CYC);							/*	デバイス更新			 */
	
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
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
