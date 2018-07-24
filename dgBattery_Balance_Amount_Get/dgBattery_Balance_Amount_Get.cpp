// tag::tracer_def[]
/*	-----------------------------------------------------------------------	 */
/*	dgBattery_Balance_Amount_Get.cpp									   	 */
/*	電圧値取得																 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/13	髙岡 諒太	 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include "dgBattery_Balance_Amount_Get.h"
#include <stdio.h>								/* 入出力ライブラリ			 */
#include <stdlib.h>								/* 標準ライブラリー			 */
#include <string.h>								/* 文字列操作系				 */
#include"..\frLog\frLog.h"							/* logヘッダー */
/* ------------------------------------------------------------------------- */
/* 関数名	: dgBattery_Balance_Amount_Get::dgBattery_Balance_Amount_Get	 */
/* 機能名	: 電圧値取得：コンストラクタ									 */
/* 機能概要	: 初回インスタンス生成時にコールされます						 */
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* 作成日	: 2018/07/13		髙岡 諒太		新規作成					 */
/* ------------------------------------------------------------------------- */
dgBattery_Balance_Amount_Get::dgBattery_Balance_Amount_Get()
{
	int  logindex  = 0;
	char command1[] = { "logon -battery\n" };
	for( logindex = 0; logindex < ( sizeof( command1 ) / sizeof(command1[0] )); logindex ++ ) {
		log.SetLog(command1[logindex]);
	}
}
/* ------------------------------------------------------------------------- */
/* 関数名	: dgBattery_Balance_Amount_Get::batteryUpdate					 */
/* 機能名	: 電圧値取得:電圧値更新											 */
/* 機能概要	: タイマ関数で定期的に電圧値を更新する							 */
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* 作成日	: 2018/07/13	髙岡 諒太		新規作成						 */
/* ------------------------------------------------------------------------- */
void dgBattery_Balance_Amount_Get::batteryUpdate() {
	/* 電圧値取得 */
	i_battery=ev3_battery_voltage_mV();
}
/* ------------------------------------------------------------------------- */
/* 関数名	: dgColor_Get::ColorGet											 */
/* 機能名	: カラー取得:カラーセンサー情報取得								 */
/* 機能概要	: 呼ばれた関数に戻り値で色情報を渡します						 */
/* 引数		: void			: なし											 */
/* 戻り値	: SINT			: i_color_info									 */
/* 作成日	: 2018/07/2		髙岡 諒太		新規作成						 */
/* ------------------------------------------------------------------------- */
SINT dgBattery_Balance_Amount_Get::batteryGet(){
	log.LOG(LOG_ID_BATTERY,"BatteryGetOk\r\n");
	return i_battery;							/* 電圧情報を戻す			 */
}
/* ------------------------------------------------------------------------- */
/* 関数名	: dgBattery_Balance_Amount_Get::GetInstance						 */
/* 機能名	: 電圧値取得:クラス実体の作成、アドレス渡し						 */
/* 機能概要	: 呼ばれた関数にクラスのアドレスを返却します					 */
/* 引数		: void			: なし											 */
/* 戻り値	: dgBattery_Balance_Amount_Get&			: obj					 */
/* 作成日	: 2018/07/13		髙岡 諒太		新規作成					 */
/* ------------------------------------------------------------------------- */
dgBattery_Balance_Amount_Get& dgBattery_Balance_Amount_Get::GetInstance(void)
{
	static dgBattery_Balance_Amount_Get obj;	/* クラス実体作成(最初のみ)	 */
	return obj;									/* クラスアドレス返却		 */
}
/* ------------------------------------------------------------------------- */
/* 関数名	: dgBattery_Balance_Amount_Get::~dgBattery_Balance_Amount_Get	 */
/* 機能名	: 電圧値取得：デストラクタ										 */
/* 機能概要	: staticクラスの為、コールされることは無い						 */
/* 引数		: void			: なし											 */
/* 戻り値	: void			: なし											 */
/* 作成日	: 2018/07/13	髙岡 諒太		新規作成						 */
/* ------------------------------------------------------------------------- */
dgBattery_Balance_Amount_Get::~dgBattery_Balance_Amount_Get()
{
}
// end::main_task[]
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */

