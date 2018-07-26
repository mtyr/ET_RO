#ifndef __MOTOR__
#define __MOTOR__
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
#include "..\common\common.h"								/* typedef�錾��			 */
#include "ev3api.h"								/* ev3api���C�u�����[		 */
/* �N���X�錾--------------------------------------------------------------- */
class dgMotor_Get{

public:
	/* public���\�b�h */
	static dgMotor_Get& GetInstance(void);		/* ���̍쐬���\�b�h			 */
	uint16_t RMotorGet();						/* �F�������n�����\�b�h	 */
	uint16_t LMotorGet();						/* �F�������n�����\�b�h	 */
	void MotorUpdate(void);						/* �p�ʒu�X�V���\�b�h		 */
	void dgMortor_OffSet();
private:
	/* private���\�b�h------------------------------------------------------ */
	dgMotor_Get();								/* �R���X�g���N�^			 */
	~dgMotor_Get();								/* �f�X�g���N�^				 */
	/* �V���O���g���ɕK�v�ȓz */
	dgMotor_Get(const dgMotor_Get &x) { };
	dgMotor_Get&operator=(const dgMotor_Get &) { return *this; };


	/* private�ϐ�---------------------------------------------------------- */
	uint16_t i_rmotor_info;							/* �擾�����E�p�ʒu���	 */
	uint16_t i_lmotor_info;							/* �擾�������p�ʒu��� */
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif