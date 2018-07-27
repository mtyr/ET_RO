/*	-----------------------------------------------------------------------	 */
/*	rsLookup_Garage.cpp												 */
/*	難所ルックアップとガレージを攻略する関数												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴									日付		氏名	 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/25	松浦 侑矢	 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	includeファイル															 */
/*	-----------------------------------------------------------------------	 */
#include "rsLookup_Garage.h"
#include "..\frLog\frLog.h"
#include "..\rnLine_Trace\rnLine_Trace.h"
#include "..\dgUltrasonic_Wave_Get\dgUltrasonic_Wave_Get.h"
#include "..\dcTail_Motor_Output\dcTail_Motor_Output.h"
/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */
void rsLookup_Garage::Capture()
{   
     
    /* クラス宣言                                                                */
    frLog &log = frLog::GetInstance();
    dgUltrasonic_Wave_Get &Ultrasonic
	 = dgUltrasonic_Wave_Get::GetInstance();
    class rnLine_Trace LineTrace;                   /*	ライントレース			 */
    class dcTail_Motor_Outputnic TailMotor;			/*	尻尾モーター			  */
    /*  ルックアップゲート処理                                                   */
    log.LOG(LOG_ID_TRACE,"RunWay_in\r\n");
    /*	尻尾モーターの下す	                                                    */
    log.LOG(LOG_ID_ERR,"tail_moter_down_in\r\n");
    TailMotor.TailStart(TAIL_DOWN);
    /*	看板までライントレース	                                                  */
    log.LOG(LOG_ID_ERR,"LineTrace_in\r\n");
    LineTrace.LineTracing();
    /* 超音波取得し、看板前まで来たか判断                                         */
    log.LOG(LOG_ID_ERR,"Ultrasonic_in\r\n");
    i_sonic = Ultrasonic.DistanceGet
    /*
        //比較処理
    */
	/*	看板抜けるまでライントレース	                                                  */
    /*
    高岡君の回転数メソッド待ち
    log.LOG(LOG_ID_ERR,"LineTrace_in\r\n");
    LineTrace.LineTracing();
    */
   
	
    DriviOder.RunWayDecision(TAIL_DOWN);
}
/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */
/* ------------------------------------------------------------------------- */
/* 関数名	:crDriving_Order::Run_Way_Decision								 */
/* 機能名	: 走行指示														 */
/* 機能概要	: ライントレースに走行指示を与える								 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/03	宇都宮  正章			新規作成				 */
/* ------------------------------------------------------------------------- */
void rsLookup_Garage::RunWay(){
	
}

void crStart_Preparation::StartPreparation(void)
{


/*	クラス宣言-------------------------------------------------------------	 */	
frLog &log = frLog::GetInstance();				/*	ログ機能の追加			 */




		
/*	尻尾もたーを上げる	*/
TailMotor.TailStart(TAIL_UP);
	    break;	
	}
}



/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
