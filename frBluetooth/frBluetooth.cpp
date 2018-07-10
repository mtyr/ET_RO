/*	-----------------------------------------------------------------------	 */
/*	frBluetooth.cpp															 */
/*	frBluetooth.hの処理内容													 */
/*	EV３とPC（Tera Term）の通信												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴									日付		氏名	 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成									2018/06/29	小西 巧  */
/*	000001	シングルトンのみ対応						2018/07/01	小西 巧	 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	includeファイル															 */
/*	-----------------------------------------------------------------------	 */
#include "frBluetooth.h"

/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */


/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::GetInstance										 */
/* 機能名	: Bluetooth通信：クラス生成										 */
/* 機能概要	:クラスの実態を返す												 */
/* 引数		:void			:なし											 */
/* 戻り値	:frBluetooth	:obj			:クラスの実態					 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
frBluetooth& frBluetooth::GetInstance(void)
{
	static frBluetooth obj;
	return obj;
}
/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::Send												 */
/* 機能名	:Bluetooth通信：送信											 */
/* 機能概要	:EV3から文字を1文字デバイスに送信								 */
/* 引数		: char			: string		:送信文字（１文字）				 */
/* 戻り値	:int			:FUNC_OK		:正常終了						 */
/*			:int			:FUNC_ERR		:異常終了						 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SINT frBluetooth::Send(SCHR  string)
{
	if( bt != NULL ){
		fprintf(bt, &string);
		return FUNC_OK;
	}
	
	return FUNC_ERR;
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::Reception											 */
/* 機能名	: Bluetooth通信：受信											 */
/* 機能概要	:デバイスから文字を1文字受信									 */
/* 引数		:void			:なし											 */
/* 戻り値	:char			:string			:受信文字(1文字)				 */
/*			:				:\0				:異常終了						 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SCHR  frBluetooth::Reception(void)
{
	if( bt != NULL ){
		return fgetc(bt);
	
	}else{
		return '\0';
	}
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::Cutting											 */
/* 機能名	: Bluetooth通信：切断											 */
/* 機能概要	:デバイスとEV3の接続を切る										 */
/* 引数		:void			:なし											 */
/* 戻り値	:int			:FUNC_OK		:正常終了						 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SINT frBluetooth::Cutting(void)
{
	if( bt!=NULL ){
		fclose(bt);
		bt=NULL;
	}
	return FUNC_OK;
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::StringSend										 */
/* 機能名	: Bluetooth通信：文字列送信										 */
/* 機能概要	:EV3からPCに文字列を送信する									 */
/* 引数		:char*			:string			:送信する文字列					 */
/* 戻り値	:int			:FUNC_OK		:正常終了						 */
/*			:int			:FUNC_ERR		:異常終了						 */
/* 作成日	: 2018/07/09	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SINT frBluetooth::StringSend(SCHR* string)
{
	SINT iRet = FUNC_ERR;
	
	/* 引数チェック */
	if( string == NULL ) {
		return iRet;
	}
	
	/* Bluetoothがオープンしていれば送信 */
	if( bt != NULL ) {
		fprintf( bt, string );
		iRet = FUNC_OK;
	}
	
	return iRet;
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::Connection										 */
/* 機能名	: Bluetooth通信：接続											 */
/* 機能概要	:EV3とPCを接続													 */
/* 引数		:なし			:				:								 */
/* 戻り値	:int			:FUNC_OK		:正常終了						 */
/*			:int			:FUNC_ERR		:異常終了						 */
/* 作成日	: 2018/07/09	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SINT frBluetooth::Connection(void)
{
	if(bt==NULL){
		bt = ev3_serial_open_file(EV3_SERIAL_BT);
		return FUNC_OK;
	}

	return FUNC_ERR;
}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::frBluetooth										 */
/* 機能名	: Bluetooth通信：コンストラクタ									 */
/* 機能概要	:初回インスタンス生成時にコール									 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
frBluetooth::frBluetooth()
{	
	/*	Buetooth接続-------------------------------------------------------	 */
	bt = ev3_serial_open_file(EV3_SERIAL_BT);
	
	/*	Bluetoothの接続失敗の時EV3のLCDに失敗を表示------------------------	 */
	if( bt == NULL ){
		ev3_lcd_draw_string	("bluetooth_connection_error\0",0,0);
	}
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::~frBluetooth										 */
/* 機能名	: Bluetooth通信：デストラクタ									 */
/* 機能概要	:staticクラスのため、コールされない								 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
frBluetooth::~frBluetooth()
{

}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
