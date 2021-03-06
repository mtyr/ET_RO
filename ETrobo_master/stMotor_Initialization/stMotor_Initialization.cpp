/*	------------------------------------------------------------------------ */
/*	stMotor.cpp															   	 */
/*	ET-ロボコン																 */
/*	初期化時に値を渡すクラス												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/07/09  有本 侑真　  */
/*  000001  改訂履歴                                2018/07/20  有本 侑真    */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include "..\common\common.h"
#include "stMotor_Initialization.h"
#include "..\frLog\frLog.h"
/*	-----------------------------------------------------------------------	 */
/*	コンストラクタ															 */
/*	-----------------------------------------------------------------------	 */
stMotor_Initialization::stMotor_Initialization(){}

/*	-----------------------------------------------------------------------	 */
/*	デストラクタ															 */
/*	-----------------------------------------------------------------------	 */
stMotor_Initialization::~stMotor_Initialization(){}

/* ------------------------------------------------------------------------- */
/* ■■■ public ■■■														 */
/* ------------------------------------------------------------------------- */

/*	-----------------------------------------------------------------------	 */
/*	public関数名	:MotorMeasurement										 */
/*	機能名			:モーター計測											 */
/*	機能概要		:各モーターの遊び範囲の値を渡す							 */
/*	引数			:SINT               : L									 */
/*                  :                   : R                                  */
/*                  :                   : T                                  */
/*	戻り値			:int				: FUNC_OK	:関数正常終了			 */
/*					:					: FUNC_ERR	:関数異常終了			 */
/*	作成日			:2018/07/09		 有本  侑真  	             新規作成	 */
/*  改訂履歴        :2018/07/20      有本  侑真                              */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::MotorMeasurement(SINT *L,SINT *R,SINT *T)
{
	frLog &log = frLog::GetInstance();
	log.LOG(LOG_ID_MOTOR,"stMotor_Initialization::MotorMeasurement\n");
	LGearPlayRange(L);                                     /* 左ギア遊び範囲 */
	RGearPlayRange(R);                                     /* 右ギア遊び範囲 */
	TailGearPlayRange(T);                                /* 尻尾ギア遊び範囲 */
	return FUNC_OK;
}

/* ------------------------------------------------------------------------- */
/* ■■■ private ■■■													 */
/* ------------------------------------------------------------------------- */

/*	---------------------------------------------------------------------- - */
/*	public関数名	:LGearPlayRange											 */
/*	機能名			:左ギア遊び範囲計測										 */
/*	機能概要		:左ギアの遊び範囲値を渡す								 */
/*	引数			:SINT 				: LGearPlayRangevalue				 */
/*	戻り値			:int				: FUNC_OK   :関数正常終了			 */
/*					:					: FUNC_ERR  :関数異常終了			 */
/*	作成日			:2018/07/10		 有本  侑真 				 新規作成	 */
/*  改訂履歴        :2018/07/20      有本  侑真                              */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::LGearPlayRange(SINT *LGearvalue)
{
	SINT LGearPlayvalue=4;
	*LGearvalue = LGearPlayvalue;					   /* 左ギアの遊び範囲値 */
	return FUNC_OK;
}

/*	---------------------------------------------------------------------- - */
/*	public関数名	:RGearPlayRange											 */
/*	機能名			:右ギア遊び範囲計測										 */
/*	機能概要		:右ギアの遊び範囲値を渡す								 */
/*	引数			:SINT 				: RGearPlayRangevalue				 */
/*	戻り値			:int				: FUNC_OK	:関数正常終了			 */
/*					:					: FUNC_ERR	:関数異常終了			 */
/*	作成日			:2018/07/10		 有本  侑真 				 新規作成	 */
/*  改訂履歴        :2018/07/20      有本  侑真                              */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::RGearPlayRange(SINT *RGearvalue)
{
	RGearPlayvalue = 4;
	*RGearvalue = RGearPlayvalue;					   /* 右ギアの遊び範囲値 */
	return FUNC_OK;
}

/*	---------------------------------------------------------------------- - */
/*	public関数名	:TailGearPlayRange										 */
/*	機能名			:尻尾ギア遊び範囲計測									 */
/*	機能概要		:尻尾ギアの遊び範囲値を渡す								 */
/*	引数			:SINT 				: TailGearPlayRangevalue			 */
/*	戻り値			:int				: FUNC_OK	:関数正常終了			 */
/*					:					: FUNC_ERR	:関数異常終了			 */
/*	作成日			:2018/07/10		 有本  侑真 				 新規作成	 */
/*  改訂履歴        :2018/07/20      有本  侑真                              */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::TailGearPlayRange(SINT *TailGearvalue)
{
	TailGearPlayvalue = 4;
	*TailGearvalue = TailGearPlayvalue;				 /* 尻尾ギアの遊び範囲値 */
	return FUNC_OK;
}
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */