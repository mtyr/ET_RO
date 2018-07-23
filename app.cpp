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
	class crStart_Preparation StartPreparation;




	StartPreparation.StartPreparation();
/*	-----------------------------------------------------------------------	 */
/*	メインループ															 */
/*	-----------------------------------------------------------------------	 */
	while(1){ }
	
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
	static frBluetooth &bluetooth = frBluetooth::GetInstance();
	static frLog &log = frLog::GetInstance();

/*	EV3のLCD表示-----------------	*/
//ev3_lcd_draw_string	("bluetooth\0",0,0);
	
/*	Bluetooth文字受信------------------------------------------------------	 */
	cNouBuf=bluetooth.Receive();
	
	/*	前文字の比較	*/
	if( cNouBuf != cBuf ){
	
        log.SetLog(cNouBuf);
		cBuf=cNouBuf;
	}
}

// end::main_task[]
