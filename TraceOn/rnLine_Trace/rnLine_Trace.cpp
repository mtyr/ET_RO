/* ------------------------------------------------------------------------- */
/* include �t�@�C��															 */
/* ------------------------------------------------------------------------- */
#include "ev3api.h"
#include "..\common\common.h"
#include "rnLine_Trace.h"
#include "..\rnInverted_Control\rnInverted_Control.h"

/* ------------------------------------------------------------------------- */
/* �R���X�g���N�^															 */
/* ------------------------------------------------------------------------- */
rnLine_Trace::rnLine_Trace(){
	/* �o�����X���s�ɕK�v�Ȃ��̂����Z�b�g���邩���߂�ϐ�					 */
	i_initialized = FALSE;
}

/* ------------------------------------------------------------------------- */
/* �f�X�g���N�^																 */
/* ------------------------------------------------------------------------- */
rnLine_Trace::~rnLine_Trace(){
	/* �X�P���g�� */
}

/* ------------------------------------------------------------------------- */
/* ���C���g���[�X															 */
/* ------------------------------------------------------------------------- */
SINT rnLine_Trace::LineTracing() {

	/* �|������N���X�̐��� */
	class rnInverted_Control myrnInverted_Control;

	/* �|�����s�ɕK�v�Ȃ��̂����Z�b�g���邩�̃`�F�b�N */
	if (i_initialized == FALSE) {
		myrnInverted_Control.Initialize();
		i_initialized = TRUE;
	}

	/* �������[�v */
	while (1)
	{
		/* �|������Class��SetCommandMethod���Ă� */
		/* PWM�l��ݒ肷�� */
		myrnInverted_Control.SetCommand(rnInverted_Control::LOW, rnInverted_Control::LOW);

		/* �|�����s���s�� */
		myrnInverted_Control.Run();

		/* 4�b�Ԑ�����󂯕t���Ȃ� */
		tslp_tsk(4);
	}
}

/* ------------------------------------------------------------------------- */
/* 				Copyright HAL College of Technology & Design				 */
/* ------------------------------------------------------------------------- */

