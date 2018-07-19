
#include "dgMotor_get.h"


/* コンストラクタ */
dgMotor_get::dgMotor_get(){
}

/* メソッド呼び出し */
I32T dgMotor_get::RotationAngleGet(){
	I32T i = 45;
	return i;
}

void dgMotor_get::reset(){
}

dgMotor_get& dgMotor_get::GetInstance(void)
{
	static dgMotor_get obj;			/* クラス実体作成(最初のみ)	 */
	return obj;									/* クラスアドレス返却		 */
}