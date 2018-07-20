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
/* 000001	インスタンス生成追加					2018/07/11	松浦 侑矢    */
/* 000002	コード修正								2018/07/15	松浦 侑矢    */

/* ------------------------------------------------------------------------- */
//
/* ------------------------------------------------------------------------- */
/* includeファイル															 */
/* ------------------------------------------------------------------------- */
#include "..\common\common.h"								/* 共通ヘッダー				 */
#include <stdio.h>								/* 基本入出力				 */
#include "..\stLine_Threshold_Value_Set\stLine_Threshold_Value_Set.h"
/* ------------------------------------------------------------------------- */
/* 定数定義																	 */
/* ------------------------------------------------------------------------- */

/* 現在カラー値一覧 -------------------------------------------------------- */
#define TS_BRACK				(			1 )		/* 黒戻り値				 */
#define TS_WHITE				(			2 )		/* 白戻り値				 */
#define TS_GRAY					(			3 )		/* 灰戻り値				 */

/* ------------------------------------------------------------------------- */
/* クラス定義																 */
/* ------------------------------------------------------------------------- */

class raLine_Threshold_Value{

public:											/*	パブリック-------------	 */	
	
	SINT raLineSet(void);						/*	現在カラー値を返信		 */		
	SINT raLineUP(SINT);						/*	現在カラー値の更新		 */
	static raLine_Threshold_Value&
		GetInstance(void);						/* 実体作成メソッド			 */
private:										/*	プライベート-----------	 */
	
	SINT i_brack;											 /* 黒値		 */
	SINT i_white;											 /* 白値		 */
	SINT i_grey;											 /* 灰値		 */
	SINT i_current_color;									 /* 現在カラー値 */

	raLine_Threshold_Value();						/* コンストラクタ		 */
	~raLine_Threshold_Value();						/* デストラクタ			 */

	/* シングルトンに必要な奴 */
	raLine_Threshold_Value(const raLine_Threshold_Value &x) { };
	raLine_Threshold_Value&operator=
		(const raLine_Threshold_Value &) { return *this; };
	stLine_Threshold_Value_Set stLine;		 /* ラインしきい値取得クラス	 */
	
};

/* ------------------------------------------------------------------------- */
/*              Copyright HAL Collage of Technology & Design                 */
/* ------------------------------------------------------------------------- */
