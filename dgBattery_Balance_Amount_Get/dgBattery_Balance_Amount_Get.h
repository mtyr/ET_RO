#ifndef __BATTERY__
#define __BATTERY__
/*	-----------------------------------------------------------------------	 */
/*	dgStatic_Color_Get.h												   	 */
/*	�J���[�Z���T�[���擾													 */
/*	-----------------------------------------------------------------------	 */
/*	�ԍ�	�X�V����								���t		����		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	�V�K�쐬								2018/05/15	���� �ȑ�	 */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	�t�@�C��														 */
/*	-----------------------------------------------------------------------	 */
#include "common.h"								/* typedef�錾��			 */
#include "ev3api.h"								/* ev3api���C�u�����[		 */
/* �N���X�錾--------------------------------------------------------------- */
class dgBattery_Balance_Amount_Get{

public:
	/* public���\�b�h */
	static dgBattery_Balance_Amount_Get& GetInstance(void);	/* ���̍쐬���\�b�h		 */
	SINT batteryGet();							/* �d���������n�����\�b�h	 */
	void batteryUpdate(void);
private:
	/* private���\�b�h------------------------------------------------------ */
	dgBattery_Balance_Amount_Get();				/* �R���X�g���N�^			 */
	~dgBattery_Balance_Amount_Get();			/* �f�X�g���N�^				 */
	/* �V���O���g���ɕK�v�ȓz */
	dgBattery_Balance_Amount_Get(const dgBattery_Balance_Amount_Get &x) { };
	dgBattery_Balance_Amount_Get&operator=(const dgBattery_Balance_Amount_Get &) { return *this; };

	/* private�ϐ�---------------------------------------------------------- */
	uint8_t i_battery;							/* �擾�����F���			 */
};
#endif