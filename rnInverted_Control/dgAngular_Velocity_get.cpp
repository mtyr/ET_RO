
#include "dgAngular_Velocity_get.h"


/* コンストラクタ */
dgAngular_Velocity_get::dgAngular_Velocity_get(){
}

/* メソッド呼び出し */
I32T dgAngular_Velocity_get::GyroGet(){
	I32T j = 77;
	return j;
}

dgAngular_Velocity_get& dgAngular_Velocity_get::GetInstance(void)
{
	static dgAngular_Velocity_get obj;			/* クラス実体作成(最初のみ)	 */
	return obj;									/* クラスアドレス返却		 */
}