/*	-----------------------------------------------------------------------	 */
/*	frBluetooth.cpp															 */
/*	frBluetooth.hの処理内容													 */
/*	EV３とPC（Tera Term）の通信												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴									日付		氏名	 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成									2018/06/29	小西 巧  */
/*	000001	シングルトンのみ対応						2018/07/01	小西 巧	 */
/*	000002	レビュー点修正								2018/07/10	小西 巧	 */
/*	000003	コメント修正								2018/07/13	小西 巧	 */
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
/* 機能概要	:EV3から1バイト送信												 */
/* 引数		:char			:string				:送信文字（１バイト）		 */
/* 戻り値	:				:FUNC_OK			:正常終了					 */
/*			:				:BLT_DIS_CONNECTED	:未接続						 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SINT frBluetooth::Send(SCHR  string)
{
	
	if( bt != NULL ){
		fprintf(bt, &string);
		return FUNC_OK;
	}
	
	return BLT_DIS_CONNECTED;
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::Receive											 */
/* 機能名	: Bluetooth通信：受信											 */
/* 機能概要	:デバイスから1バイト受信										 */
/* 引数		:void			:なし											 */
/* 戻り値	:char			:					:受信データ(1バイト)		 */
/*			:				:BLT_DIS_CONNECTED	:未接続						 */
/*			:				:EOF				:読み込みエラー				 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SCHR  frBluetooth::Receive(void)
{
	if( bt != NULL ){
		return fgetc(bt);
	}
	return BLT_DIS_CONNECTED;
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::DisConnect										 */
/* 機能名	: Bluetooth通信：切断											 */
/* 機能概要	:デバイスとEV3のBluetooth接続を切る								 */
/* 引数		:void			:なし											 */
/* 戻り値	:				:BLT_DIS_CONNECTED	:未接続						 */
/*			:				:EOF				:クローズ失敗				 */
/*			:				:FUNC_OK			:正常終了					 */
/* 作成日	: 2018/07/01	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SINT frBluetooth::DisConnect(void)
{
	SINT i_ret = EOF;							/*	戻り値の判断			 */
	
	
	if( bt != NULL ){
		
		/*	戻り値判断	*/
		i_ret = fclose(bt);
		
		if( EOF == i_ret ){
			return i_ret;
		}

		bt = NULL;
		return FUNC_OK;
	}

	return BLT_DIS_CONNECTED;
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::StringSend										 */
/* 機能名	: Bluetooth通信：文字列送信										 */
/* 機能概要	:EV3からデバイスに文字列を送信する								 */
/* 引数		:char*			:string				:送信する文字列				 */
/* 戻り値	:				:FUNC_OK			:正常終了					 */
/*			:				:BLT_DIS_CONNECTED	:未接続						 */
/*			:				:BLT_ARG_ERROR		:引数エラー					 */
/* 作成日	: 2018/07/09	小西 巧			新規作成						 */
/* ------------------------------------------------------------------------- */
SINT frBluetooth::StringSend(SCHR* string)
{
	SINT i_ret = BLT_DIS_CONNECTED;				/*	戻り値格納	*/
	
	/* 引数チェック */
	if( string == NULL ) {
		i_ret=BLT_ARG_ERROR;
		return i_ret;
	}
	
	/* Bluetoothがオープンしていれば送信 */
	if( bt != NULL ) {
		fprintf( bt, string );
		i_ret = FUNC_OK;
	}
	
	return i_ret;
}

/* ------------------------------------------------------------------------- */
/* 関数名	:frBluetooth::Connect											 */
/* 機能名	: Bluetooth通信：接続											 */
/* 機能概要	:EV3とPCをBluetooth接続する										 */
/* 引数		:なし			:					:							 */
/* 戻り値	:				:FUNC_OK			:正常終了					 */
/*			:				:BLT_DIS_CONNECTED	:未接続						 */
/*			:				:BLT_CONNECTED		:接続済み					 */
/* 作成日	: 2018/07/09	小西 巧				新規作成					 */
/* ------------------------------------------------------------------------- */
SINT frBluetooth::Connect(void)
{

	if(bt == NULL){
		bt = ev3_serial_open_file(EV3_SERIAL_BT);
		
		if( bt != NULL ){
			return FUNC_OK;
			
		}else{
			return BLT_DIS_CONNECTED;
		}
	}

	return BLT_CONNECTED;
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
