// tag::tracer_def[]
#include "app.h"
#include "common\common.h"
#include "crDriving_Order\crDriving_Order.h"
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
	class crDriving_Order DrivingOrder;
	
    /* Bluetooth通信タスクの起動 */
	//sta_cyc(BT_CYC);
	
/*	EV3LCD表示-------------------------------------------------------------	 */

	//ev3_lcd_draw_string	("bluetooth1\0",0,0);

	DrivingOrder.RunWayDecision();
/*	-----------------------------------------------------------------------	 */
/*	メインループ															 */
/*	-----------------------------------------------------------------------	 */
	while(1){ }
	
  ext_tsk();
}

// end::main_task[]
