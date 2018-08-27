/*	-----------------------------------------------------------------------	 */
/*	seesaw.cpp														 */
/*	シーソークラス															 */
/*	難所のシーソー部分を走行するクラス											 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴							日付		氏名			 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成							2018/07/27	髙岡　諒太	 */
/*	-----------------------------------------------------------------------	 */
/*	----------------------------------------------------------------------	 */
/*	includeファイル														 	 */
/*	----------------------------------------------------------------------	 */
#include "rnLine_Trace.h"
#include "dcMotor_Output.h"
#include "dcTail_Motor_Output.h"
/* ------------------------------------------------------------------------- */
/* 関数名	:rsSeesaw::rsSeesaw												 */
/* 機能名	:シーソーのコンストラクタ										 */
/* 機能概要	: シーソーのコンストラクタ										 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/31	高岡　諒太			新規作成					 */
/* ------------------------------------------------------------------------- */
void rsSeesaw::rsSeesaw(){

}
/* ------------------------------------------------------------------------- */
/* 関数名	:rsSeesaw::LineTrace										 */
/* 機能名	:ライントレース走行を行う										 */
/* 機能概要	: ライントレースに走行指示を与える								 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/27	高岡　諒太			新規作成				 */
/* ------------------------------------------------------------------------- */
void rsSeesaw::LineTrace(){
	/* クラス宣言------------------------------------------------------------ */
	class rnLine_Trace LineTrace;					/* ライントレースクラス */
	class dcMotor_Output MotorOut;					/* モーターアウトプットクラス */
	class dcTail_Motor_Output TailOut;				/* モーターアウトプットクラス */
	dgAngular_Velocity_Get &gyro = dgAngular_Velocity_Get::GetInstance();/* ジャイロセンサー取得クラス */
	dgMotor_Get &motor = dgMotor_Get::GetInstance();/* モーター取得クラス */
	Inverted &myinverted=Inverted::GetInstance();/* 倒立制御クラス */
	/* 変数宣言-------------------------------------------------------------- */
	FLOT f_distance=0;
	SINT i_gyro_info=0;
	LineTrace.LineTracing(/*難所モード設定*/));		/* ライントレース走行 */

	/* ライン見てまっすぐに姿勢ただす（Line_Traceクラスのメソッド） */

	/* シーソー降りるまで走行 */
	while(i_gyro_info<100){						/*数値は走行させて調整*/
		i_gyro_info=gyro.GyroGet();
		Inverted::DriviParame((FLOT)80,(FLOT)0);
	}
	MotorOut.MotorOutput(0,0);		/* ストップ */
	TailOut.TailMotorOutput(75);	/* ガレージ停車 */
}
/* ------------------------------------------------------------------------- */
/* 関数名	:rsSeesaw::rsSeesaw												 */
/* 機能名	:シーソーのデストラクタ										 */
/* 機能概要	: シーソーのデストラクタ										 */
/* 引数		:void			:なし											 */
/* 戻り値	:void			:なし											 */
/* 作成日	: 2018/07/31	高岡　諒太			新規作成					 */
/* ------------------------------------------------------------------------- */
void rsSeesaw::~rsSeesaw(){

}