
#include "dgBattery_Balance_Amount_get.h"


/* �R���X�g���N�^ */
dgBattery_Balance_Amount_get::dgBattery_Balance_Amount_get(){
}

/* ���\�b�h�Ăяo�� */
 I32T dgBattery_Balance_Amount_get::VoltageGet(){
	I32T m = 45;
	return m;
}

dgBattery_Balance_Amount_get& dgBattery_Balance_Amount_get::GetInstance(void)
{
	static dgBattery_Balance_Amount_get obj;			/* �N���X���̍쐬(�ŏ��̂�)	 */
	return obj;									/* �N���X�A�h���X�ԋp		 */
}