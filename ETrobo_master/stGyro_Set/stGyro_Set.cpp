/*	------------------------------------------------------------------------ */
/*	stGyro_Set.cpp														   	 */
/*	ET-ロボコン																 */
/*	初期化時にジャイロセンサーの値のセットを指示するクラス					 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/06/26  宇都宮  正章 */
/*	000001	文字コード、改行コード変更				2018/07/20	宇都宮  正章 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include"stGyro_Set.h"
#include"..\dgAngular_Velocity_Get\dgAngular_Velocity_Get.h"
#include"..\frLog\frLog.h"

/*	-----------------------------------------------------------------------	 */
/*	コンストラクタ															 */
/*	-----------------------------------------------------------------------	 */
stGyro_Set::stGyro_Set(){

}

/*	-----------------------------------------------------------------------	 */
/*	デストラクタ															 */
/*	-----------------------------------------------------------------------	 */
stGyro_Set::~stGyro_Set(){

}

/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */

/*	-----------------------------------------------------------------------	 */
/*	public関数名	:OffsetStart											 */
/*	機能名			:ジャイロセンサーのオフセットを開始する					 */
/*	機能概要		:INフォルダの指定された画像を読み込む					 */
/*	引数			:無し													 */
/*	戻り値			:int				:FUNC_OK	:関数正常終了			 */
/*	作成日			:2018/06/26			宇都宮  正章			新規作成	 */
/*	-----------------------------------------------------------------------	 */
SINT stGyro_Set::OffSetStart(){
	SINT i_gyro_set = 0;
	SINT i_loop = 0;
	frLog &log = frLog::GetInstance();
	log.LOG(LOG_ID_GYRO,"stGyro_class_in\n");

	
	/* ジャイロセンサーの値を受け取る */
	dgAngular_Velocity_Get & GyroGet 
		= dgAngular_Velocity_Get::GetInstance();


	while (i_loop == 0){
		i_gyro_set = GyroGet.OffSet();
		if (i_gyro_set != FUNC_ERR){
			/* エラー時のみループを続ける */
			i_loop = 1;
			log.LOG(LOG_ID_ERR,"GyroGetclassOK\n");
		}
		log.LOG(LOG_ID_GYRO,"stGyro_class_out\n");
	}
	return FUNC_OK;
}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
