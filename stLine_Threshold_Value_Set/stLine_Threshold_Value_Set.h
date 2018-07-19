#pragma once
/* ------------------------------------------------------------------------- */
/* stLine_Threshold_Value_set.h												 */
/* ETロボコン開発															 */
/* しきい値保存クラス									 				　　 */
/*																			 */
/* ------------------------------------------------------------------------- */
/* 	番号	更新内容								更新日		名前		 */
/* ------------------------------------------------------------------------- */
/* 000000	新規作成								2018/06/22	松浦　侑矢   */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* includeファイル															 */
/* ------------------------------------------------------------------------- */
#include "common.h"								/* 共通ヘッダー				 */
#include <stdio.h>								/* 基本入出力				 */
/* ------------------------------------------------------------------------- */
/* クラス定義																 */
/* ------------------------------------------------------------------------- */

class stLine_Threshold_Value_Set{

public:											/*	パブリック-------------	 */

	SINT UP(void);								/*	しきい値を返信			 */
	void Get(SINT);								/*	しきい値設定	　　   	 */
private:										/*	プライベート-----------	 */
	SINT 
};

/* ------------------------------------------------------------------------- */
/*              Copyright HAL Collage of Technology & Design                 */
/* ------------------------------------------------------------------------- */
