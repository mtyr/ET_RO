/* ------------------------------------------------------------------------- */
/*	rnCalculation_Cpp.cpp                                                    */
/*	<EV3ライントレース>ソフトウェア開発                                      */
/*  走行用計算管理クラス                                                     */
/*	倒立制御クラスからの指示で走行用計算を管理する                           */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	番号		更新履歴							日付		氏名		 */
/*	-----------------------------------------------------------------------  */
/*	000000		新規作成							2018/07/11	田邉  周哉	 */
/* ------------------------------------------------------------------------- */

#include "rnCalculation.h"
#include "rnCalculation_Cpp.h"

/* ------------------------------------------------------------------------- */
/* コンストラクタ                                                            */
/* ------------------------------------------------------------------------- */
rnCalculation::rnCalculation()                  /* メンバイニシャライザ      */
    : i_forward(0),                             /* 前進値                    */
	  i_turn(0),                                /* 旋回値                    */
	  i_offset(0),                              /* ジャイロセンサ値          */
	  i_right_pwm(0),                           /* 右モーターPWM値           */
	  i_left_pwm(0) {                           /* 左モーターPWM値           */
}

/* ------------------------------------------------------------------------- */
/*	関数名		:Initialize                                                  */
/*	機能名		:倒立制御仕使用値初期化                                      */
/*	機能概要	:走行用計算に使用する変数を初期化する                        */
/*	引数		:SINT           offset          ジャイロセンサ値             */
/*  戻り値      :無し                                                        */
/*	作成日		:2018/07/11		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
void rnCalculation::Initialize(SINT offset) {
	/* ジャイロセンサ値初期化 */
    i_offset = offset;
	/* 倒立振子制御初期化 */
	Calculation_Initialize();
}

/* ------------------------------------------------------------------------- */
/*	関数名		:Update                                                      */
/*	機能名		:モーター出力値計算                                          */
/*	機能概要	:モーター出力値の計算を指示。戻り値にPWM値を得る             */
/*	引数		:SINT           angle                  角速度                */
/*              :SINT           right_wheel_encoder    右車輪エンコーダ値    */
/*				:SINT           left_wheel_encoder     左車輪エンコーダ値    */
/*				:SINT           battery                バッテリー電圧値      */
/*  戻り値      :無し                                                        */
/*	作成日		:2018/07/11		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
void rnCalculation::Update(SINT angle, SINT right_wheel_encoder, 
	                                   SINT left_wheel_encoder, SINT battery) {
    /* 倒立走行するための左右モータ出力値を得る */
	Calculation_Control(
        static_cast<FLOT>(i_forward),
        static_cast<FLOT>(i_turn),
        static_cast<FLOT>(angle),
        static_cast<FLOT>(i_offset),
		static_cast<FLOT>(CancelBacklash(i_left_pwm, left_wheel_encoder)),
		static_cast<FLOT>(CancelBacklash(i_right_pwm, right_wheel_encoder)),
        static_cast<FLOT>(battery),
        &i_left_pwm,
        &i_right_pwm);
}

/* ------------------------------------------------------------------------- */
/*	関数名		:SetCommand                                                  */
/*	機能名		:PWM値設定                                                   */
/*	機能概要	:PWM値を設定する                                             */
/*	引数		:SINT           forward         前進値                       */
/*              :SINT           turn            旋回値                       */
/*  戻り値      :無し                                                        */
/*	作成日		:2018/07/11		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
void rnCalculation::SetCommand(SINT forward, SINT turn) {
    i_forward = forward;
    i_turn    = turn;
}

/* ------------------------------------------------------------------------- */
/*	関数名		:GetPwmRight                                                 */
/*	機能名		:PWM値取得                                                   */
/*	機能概要	:右モーターのPWM値を取得する                                 */
/*	引数		:無し                                                        */
/*  戻り値      :int8_t                         右モーター出力値             */
/*	作成日		:2018/07/11		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
I08T rnCalculation::GetPwmRight() {
    return i_right_pwm;
}

/* ------------------------------------------------------------------------- */
/*	関数名		:GetPwmLeft                                                  */
/*	機能名		:PWM値取得                                                   */
/*	機能概要	:左モーターのPWM値を取得する                                 */
/*	引数		:無し                                                        */
/*  戻り値      :int8_t                         左モーター出力値             */
/*	作成日		:2018/07/11		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
I08T rnCalculation::GetPwmLeft() {
    return i_left_pwm;
}

/* ------------------------------------------------------------------------- */
/*	関数名		:CancelBacklash                                              */
/*	機能名		:バックラッシュ補正                                          */
/*	機能概要	:取得したモーターPWM値と前回の出力値を比較し、               */
/*               モーターの遊びを追加した値を生成する                        */
/*	引数		:int8_t         pwm             PWM値（前回の出力値）        */
/*               SINT           encoder         モーター取得値               */
/*  戻り値      :int8_t                         遊びを追加した修正値         */
/*	作成日		:2018/07/11		田邉周哉		新規作成		　　　		 */
/* ------------------------------------------------------------------------- */
SINT rnCalculation::CancelBacklash(I08T pwm, SINT encoder) {
    const SINT BacklashHalf = 4;  // バックラッシュの半分[deg]
	/* 前回の出力値が0のとき */
	if (pwm == 0) return encoder;
	/* 前回の出力値が0より比較（左辺：大きい、右辺：小さい） */
	return pwm > 0 ? encoder - BacklashHalf : encoder + BacklashHalf;
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
