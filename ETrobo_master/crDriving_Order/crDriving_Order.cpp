/*	-----------------------------------------------------------------------	 */
/*	crDriving_Order.cpp														 */
/*	走行指示クラス															 */
/*	走行開始を支持するクラス												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴							日付		氏名			 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成							2018/07/03	宇都宮  正章	 */
/*	000001	文字コード、改行コード変更			2018/07/20	宇都宮  正章	 */
/*	-----------------------------------------------------------------------	 */

/*	----------------------------------------------------------------------	 */
/*	includeファイル														 	 */
/*	----------------------------------------------------------------------	 */
#include "crDriving_Order.h"
#include "..\rnLine_Trace\rnLine_Trace.h"
#include"..\frLog\frLog.h"
//#include "frDifficulty.h"

/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* 関数名	:crDriving_Order::crDriving_Order								 */
/* 機能名	: 走行指示：コンストラクタ										 */
/* 機能概要	:何したら														 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/03	宇都宮  正章			新規作成				 */
/* ------------------------------------------------------------------------- */
crDriving_Order::crDriving_Order()
{

}

/* ------------------------------------------------------------------------- */
/* 関数名	:crDriving_Order::crDriving_Order								 */
/* 機能名	: 走行指示：デストラクタ										 */
/* 機能概要	:何したら														 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/03	宇都宮  正章			新規作成				 */
/* ------------------------------------------------------------------------- */
crDriving_Order::~crDriving_Order()
{

}

/* ------------------------------------------------------------------------- */
/* 関数名	:crDriving_Order::Run_Way_Decision								 */
/* 機能名	: 走行指示														 */
/* 機能概要	: ライントレースに走行指示を与える								 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/03	宇都宮  正章			新規作成				 */
/* ------------------------------------------------------------------------- */
void crDriving_Order::RunWayDecision(){
	/*	クラス宣言	*/
	rnLine_Trace LineTrace;						/*	ライントレースクラス	 */
	
	LineTrace.LineTracing();
	
	//void Difficulty();
}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* 関数名	:crDriving_Order::Defficulty									 */
/* 機能名	: 難所走行														 */
/* 機能概要	: 難所走行指示を与える											 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/03	宇都宮  正章			新規作成				 */
/* ------------------------------------------------------------------------- */
/*void crDriving_Order::Difficulty(){
	//難所クラスに名前書く
	//class frDifficulty d;
	//d.dif();
}*/
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
