
#include "dgMotor_get.h"


/* �R���X�g���N�^ */
dgMotor_get::dgMotor_get(){
}

/* ���\�b�h�Ăяo�� */
I32T dgMotor_get::RotationAngleGet(){
	I32T i = 45;
	return i;
}

void dgMotor_get::reset(){
}

dgMotor_get& dgMotor_get::GetInstance(void)
{
	static dgMotor_get obj;			/* �N���X���̍쐬(�ŏ��̂�)	 */
	return obj;									/* �N���X�A�h���X�ԋp		 */
}