
#include "dgAngular_Velocity_get.h"


/* �R���X�g���N�^ */
dgAngular_Velocity_get::dgAngular_Velocity_get(){
}

/* ���\�b�h�Ăяo�� */
I32T dgAngular_Velocity_get::GyroGet(){
	I32T j = 77;
	return j;
}

dgAngular_Velocity_get& dgAngular_Velocity_get::GetInstance(void)
{
	static dgAngular_Velocity_get obj;			/* �N���X���̍쐬(�ŏ��̂�)	 */
	return obj;									/* �N���X�A�h���X�ԋp		 */
}