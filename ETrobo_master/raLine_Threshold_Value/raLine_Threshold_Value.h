#pragma once
/* ------------------------------------------------------------------------- */
/* raLine_Threshold_Value.h													 */
/* ETロボコン開発															 */
/* しきい値保存クラス									 				     */
/*																			 */
/* ------------------------------------------------------------------------- */
/* 	番号	更新内容								更新日		名前		 */
/* ------------------------------------------------------------------------- */
/* 000000	新規作成								2018/06/22	松浦 侑矢    */
/* ------------------------------------------------------------------------- */
//
/* ------------------------------------------------------------------------- */
/* includeファイル															 */
/* ------------------------------------------------------------------------- */
#include "..\common\common.h"					/* 共通ヘッダー				 */
#include <stdio.h>								/* 基本入出力				 */
#include "PIDCalculator.h"
#include "MathHelper.h"
/* ------------------------------------------------------------------------- */
/* 定数定義																	 */
/* ------------------------------------------------------------------------- */

/* 現在カラー値一覧 -------------------------------------------------------- */
#define TS_BLACK				(			1 )		/* 黒戻り値				 */
#define TS_WHITE				(			2 )		/* 白戻り値				 */
#define TS_GRAY					(			3 )		/* 灰戻り値				 */
#define DELTA_T					(		0.004 )		/* 処理周期4msecの場合	 */
#define KP						(		  1.0 )		/* 定数					 */
#define KI						(		  0.0 )		/* 定数				 	 */
#define KD						(		  0.0 )		/* 定数				 	 */

/* ------------------------------------------------------------------------- */
/* クラス定義																 */
/* ------------------------------------------------------------------------- */

class raLine_Threshold_Value{

public:											/*	パブリック-------------	 */	
		raLine_Threshold_Value();					/* コンストラクタ		 */
	~raLine_Threshold_Value();						/* デストラクタ			 */

	
	SINT raLineSet(void);						/*	現在カラー値を返信		 */		
	SINT raLineGet(SINT);						/*	現在カラー値の更新		 */
	SINT raLineUP(SINT);						/*	しきい値取得			 */
	static raLine_Threshold_Value&
		GetInstance(void);						/* 実体作成メソッド			 */
private:										/*	プライベート-----------	 */
	FLOT raLinePID(SINT ,SINT );						/*	しきい値取得	 */
	FLOT Turning;
	//SINT i_black;											 /* 黒値		 */
	//SINT i_white;											 /* 白値		 */
	SINT i_gray;											 /* 灰値		 */
	SINT i_current_color;									 /* 現在カラー値 */
	
	FLOT P;
	FLOT I;
	FLOT D;
	FLOT PID;

	/* シングルトンに必要な奴 */
	raLine_Threshold_Value(const raLine_Threshold_Value &x) { };
	raLine_Threshold_Value&operator=
		(const raLine_Threshold_Value &) { return *this; };
	
	/*	クラス宣言	*/
	PIDCalculator PIDCal;
};

/* ------------------------------------------------------------------------- */
/*              Copyright HAL Collage of Technology & Design                 */
/* ------------------------------------------------------------------------- */
