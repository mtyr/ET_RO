#pragma once
/* ------------------------------------------------------------------------- */
/* stLine_Threshold_Value_set.h												 */
/* ETロボコン開発															 */
/* しきい値保存クラス									 				     */
/*																			 */
/* ------------------------------------------------------------------------- */
/* 	番号	更新内容								更新日		名前		 */
/* ------------------------------------------------------------------------- */
/* 000000	新規作成								2018/06/22	松浦 侑矢    */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* includeファイル															 */
/* ------------------------------------------------------------------------- */
#include "..\common\common.h"								/* 共通ヘッダー				 */
#include <stdio.h>								/* 基本入出力				 */
/* ------------------------------------------------------------------------- */
/* クラス定義																 */
/* ------------------------------------------------------------------------- */

class stLine_Threshold_Value_Set{

public:											/*	パブリック-------------	 */

	SINT stLineUP(void);								/*	しきい値を返信	 */
	void stLineGet(SINT);								/*	しきい値設定	 */
private:										/*	プライベート-----------	 */
	SINT stLineGRAY(void);
	SINT i_black;											 /* 黒値		 */
	SINT i_white;											 /* 白値		 */
	SINT i_gray;											 /* 灰値		 */
};

/* ------------------------------------------------------------------------- */
/*              Copyright HAL Collage of Technology & Design                 */
/* ------------------------------------------------------------------------- */
