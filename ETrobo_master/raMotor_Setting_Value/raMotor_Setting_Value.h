/*	-----------------------------------------------------------------------	 */
/*	raMotor_Setting_Value.h													 */
/*	モーター設定値のクラスヘッダ											 */
/*	型名のtypedef宣言の集まり												 */
/*	-----------------------------------------------------------------------	 */
/*	番号	更新履歴								日付		氏名		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	新規作成								2018/06/05	宇都宮　正章 */
/*  000001  改訂履歴                                2018/07/20  有本 侑真    */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	include	ファイル														 */
/*	-----------------------------------------------------------------------	 */
#include"..\common\common.h"

/*	-----------------------------------------------------------------------	 */
/*	typedef宣言																 */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	クラスの宣言															 */
/*	-----------------------------------------------------------------------	 */
class raMotor_Setting_Value{
public:
	raMotor_Setting_Value();
	~raMotor_Setting_Value();
	SINT MotorValueSet(SINT*,SINT*,SINT*); /* モーターの設定値を決める */
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */