#ifndef __SONIC__
#define __SONIC__
/*	-----------------------------------------------------------------------	 */
/*	dgUltrasonic_Wave_Get.h												   	 */
/*	�������擾															 */
/*	-----------------------------------------------------------------------	 */
/*	�ԍ�	�X�V����								���t		����		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	�V�K�쐬								2018/07/13	���� �ȑ�	 */
/*	-----------------------------------------------------------------------	 */
/*	-----------------------------------------------------------------------	 */
/*	include	�t�@�C��														 */
/*	-----------------------------------------------------------------------	 */
#include "common.h"								/* typedef�錾��			 */
#include "ev3api.h"								/* ev3api���C�u�����[		 */
/* �N���X�錾--------------------------------------------------------------- */
class dgUltrasonic_Wave_Get{

public:
	/* public���\�b�h */
	static dgUltrasonic_Wave_Get& GetInstance(void);	/* ���̍쐬���\�b�h	 */
	int16_t DistanceGet();							/* �F�������n�����\�b�h	 */
	void DistanceUpdate(void);					/* �������X�V���\�b�h		 */
private:
	/* private���\�b�h------------------------------------------------------ */
	dgUltrasonic_Wave_Get();						/* �R���X�g���N�^		 */
	~dgUltrasonic_Wave_Get();						/* �f�X�g���N�^			 */
	/* �V���O���g���ɕK�v�ȓz */
	dgUltrasonic_Wave_Get(const dgUltrasonic_Wave_Get &x) { };
	dgUltrasonic_Wave_Get&operator=(const dgUltrasonic_Wave_Get &) { return *this; };
	/* private�ϐ�---------------------------------------------------------- */
	int16_t i_distance_info;						/* �擾�����������		 */
};
#endif