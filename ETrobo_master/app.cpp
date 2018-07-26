// tag::tracer_def[]
#include "app.h"
#include "frLog.h"
#include "common.h"
#include "frBluetooth.h"
#include <string.h>

/* LCDフォントサイズ */
#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (6/*TODO: magic number*/)
#define CALIB_FONT_HEIGHT (8/*TODO: magic number*/)


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

// end::tracer_def[]
// tag::main_task[]

/*	-----------------------------------------------------------------------	 */
/*	メインタスク															 */
/*	-----------------------------------------------------------------------	 */
void main_task(intptr_t unused) {
/*	変数宣言---------------------------------------------------------------	 */
	SCHR c_buf=0;/*	受信用	*/
/*	クラス宣言-------------------------------------------------------------	 */
	frBluetooth &bluetooth = frBluetooth::GetInstance();
	frLog &log = frLog::GetInstance();

    /* Bluetooth通信タスクの起動 */
	sta_cyc(BT_CYC);
	
/*	-----------------------------------------------------------------------	 */
/*	メインループ															 */
/*	-----------------------------------------------------------------------	 */
	while(1){
		log.LOG(LOG_ID_MOTOR,"MotorTest\r\n");
		tslp_tsk(1);
	}
	
  ext_tsk();
}

// end::main_task[]
