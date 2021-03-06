/*	-----------------------------------------------------------------------	 */
/*	stMotor_Set.h															 */
/*	モーター初期化															 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/06/25	有本  侑真	 */
/*  000001  改訂履歴                                2018/07/20  有本  侑真   */
/*	-----------------------------------------------------------------------	 */

/*  -----------------------------------------------------------------------  */
/*  includeファイル                                                          */
/*  -----------------------------------------------------------------------  */
#include "..\common\common.h"

/*  -----------------------------------------------------------------------  */
/*  クラス宣言                                                               */
/*  -------------------------------------------------------------------------*/
class stMotor_Initialization
{
public:
	stMotor_Initialization();                              /* コンストラクタ */
	~stMotor_Initialization();                               /* デストラクタ */
	SINT MotorMeasurement(SINT*,SINT*,SINT*);        /* モーターの計測 */
private:
	SINT LGearPlayRange(SINT*);                          /* 左ギアの遊び範囲 */
	SINT RGearPlayRange(SINT*);                          /* 右ギアの遊び範囲 */
	SINT TailGearPlayRange(SINT*);                     /* 尻尾ギアの遊び範囲 */
	SINT LGearPlayvalue;								 /* 左ギア遊び範囲値 */
	SINT RGearPlayvalue;                                 /* 右ギア遊び範囲値 */
	SINT TailGearPlayvalue;                            /* 尻尾ギア遊び範囲値 */
};
