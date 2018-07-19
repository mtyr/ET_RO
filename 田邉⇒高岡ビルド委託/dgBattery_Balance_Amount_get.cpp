
#include "dgBattery_Balance_Amount_get.h"


/* コンストラクタ */
dgBattery_Balance_Amount_get::dgBattery_Balance_Amount_get(){
}

/* メソッド呼び出し */
 I32T dgBattery_Balance_Amount_get::VoltageGet(){
	I32T m = 45;
	return m;
}

dgBattery_Balance_Amount_get& dgBattery_Balance_Amount_get::GetInstance(void)
{
	static dgBattery_Balance_Amount_get obj;			/* クラス実体作成(最初のみ)	 */
	return obj;									/* クラスアドレス返却		 */
}