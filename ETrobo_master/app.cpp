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
/*	変数宣言---------------------------------------------------------------	 */
	
/*	変数初期化-------------------------------------------------------------	 */
	
/*	クラス宣言-------------------------------------------------------------	 */
	
	/* bluetoothハンドラの開始	*/
	sta_cyc(BT_CYC);
	//デバイスのハンドラ
	sta_cyc(DC_CYC);
	
	
	crStart_Preparation StPrepara;


frLog &log = frLog::GetInstance();
	
log.LOG(LOG_ID_ERR,"log_start\r\n");
	StPrepara.StartPreparation();
/*	-----------------------------------------------------------------------	 */
/*	メインループ															 */
/*	-----------------------------------------------------------------------	 */
	//while(1){ }
	
  ext_tsk();
}

/*	-----------------------------------------------------------------------	 */
/*	デバイス周期ハンドラ													 */
/*	-----------------------------------------------------------------------	 */
void dc_cyc(intptr_t unused)
{
//ジャイロ
dgAngular_Velocity_Get &gyro = dgAngular_Velocity_Get::GetInstance();
	
//バッテリ
dgBattery_Balance_Amount_Get &battery =dgBattery_Balance_Amount_Get::GetInstance();

//カラー
dgColor_Get &color =dgColor_Get::GetInstance();
	
	gyro.GyroUpdate();
	battery.batteryUpdate();
	color.ColorUpdate();
	
}

/*	-----------------------------------------------------------------------	 */
/*	Bluetoothタイマー割込み													 */
/*	-----------------------------------------------------------------------	 */
void bt_cyc(intptr_t unused)
{
/*	変数宣言---------------------------------------------------------------	 */
static	SCHR cBuf;								/*	受信時の比較用配列		 */
	
/*	クラス宣言-------------------------------------------------------------	 */
	 frBluetooth &bluetooth = frBluetooth::GetInstance();
	 frLog &log = frLog::GetInstance();

/*	Bluetooth文字受信------------------------------------------------------	 */
	cBuf = bluetooth.Receive();
	
	/*	比較	*/
	if( cBuf != EOF ){
		/*	ログの出力	*/
		///log.LOG(LOG_ID_ERR,"LogSet:");
		log.LOG(LOG_ID_ERR,&cBuf);
		log.LOG(LOG_ID_ERR,"\r\n");
		/*	ログのIDセット	*/
        log.SetLog(cBuf);
		cBuf=EOF;
	}
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
