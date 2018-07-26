#ifndef __COLOR__
#define __COLOR__
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
class dgColor_Get{

public:
	/* public���\�b�h */
	static dgColor_Get& GetInstance(void);		/* ���̍쐬���\�b�h			 */
	uint8_t ColorGet();							/* �p�ʒu�������n�����\�b�h*/
	void ColorUpdate(void);						/* �p�ʒu���X�V			 */
private:
	/* private���\�b�h------------------------------------------------------ */
	dgColor_Get();								/* �R���X�g���N�^			 */
	~dgColor_Get();								/* �f�X�g���N�^				 */
	/* �V���O���g���ɕK�v�ȓz */
	dgColor_Get(const dgColor_Get &x) { };
	dgColor_Get&operator=(const dgColor_Get &) { return *this; };
	/* private�ϐ�---------------------------------------------------------- */
	uint8_t i_color_info;							/* �擾�����F���		 */
};
/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
#endif