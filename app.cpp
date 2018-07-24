// tag::tracer_def[]
#include "app.h"
#include "common\common.h"
#include "crStart_Preparation\crStart_Preparation.h"
#include "frLog\frLog.h"
#include "frBluetooth\frBluetooth.h"
#include <string.h>
//using namespace ev3api;

/* LCDフォントサイズ */
#define CALIB_FONT (EV3_FONT_SMALL)
#define CALIB_FONT_WIDTH (6/*TODO: magic number*/)
#define CALIB_FONT_HEIGHT (8/*TODO: magic number*/)

// end::tracer_def[]
// tag::main_task[]

/*	-----------------------------------------------------------------------	 */
/*	メインタスク															 */
/*	-----------------------------------------------------------------------	 */
void main_task(intptr_t unused) {
/*	変数宣言---------------------------------------------------------------	 */
	
/*	変数初期化-------------------------------------------------------------	 */
	
/*	クラス宣言-------------------------------------------------------------	 */
	
	/* bluetoothハンドラの開始	*/
	sta_cyc(BT_CYC);
	
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
/*	Bluetoothタイマー割込み													 */
/*	-----------------------------------------------------------------------	 */
void bt_cyc(intptr_t unused)
{
/*	変数宣言---------------------------------------------------------------	 */
static	SCHR cNouBuf;							/*	受信文字の格納			 */

static	SCHR cBuf;								/*	受信時の比較用配列		 */
	
/*	クラス宣言-------------------------------------------------------------	 */
	 frBluetooth &bluetooth = frBluetooth::GetInstance();
	 frLog &log = frLog::GetInstance();

/*	Bluetooth文字受信------------------------------------------------------	 */
	cNouBuf=bluetooth.Receive();
	
	/*	前文字の比較	*/
	if( cNouBuf != cBuf ){
	
        log.SetLog(cNouBuf);
		cBuf=cNouBuf;
	}
}

// end::main_task[]
