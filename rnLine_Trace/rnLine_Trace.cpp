/* ------------------------------------------------------------------------- */
/* rnLine_Trace.cpp                                                          */
/* ET���{�R���J��                                                            */
/* ���C���g���[�X�@�\�ł��B                                                  */
/*                                                                           */
/* ------------------------------------------------------------------------- */
/* �ԍ�   �X�V����                             ���t         ����             */
/* ------------------------------------------------------------------------- */
/* 000000 �V�K�쐬                             2018/07/02   �b�c�@�[�N       */
/* 000001 �֐��w�b�_�̋L��                     2018/07/03   �b�c�@�[�N       */
/* 000002 Color_Running���\�b�h�̒ǉ��쐬      2018/07/10   �b�c�@�[�N       */
/* 000003 �R�[�f�B���O���r���[�C���_�̏C��     2018/07/12   �b�c�@�[�N       */
/* 000004 �R�[�f�B���O���r���[�C���_�̏C��     2018/07/13   �b�c�@�[�N       */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/* include �t�@�C��                                                          */
/* ------------------------------------------------------------------------- */
#include "common.h"
#include "rnLine_Trace.h"
#include "raLine_Threshold_Value.h"


/* ------------------------------------------------------------------------- */
/* �֐���   :rnLine_Trace                                                    */
/* �@�\��   :�R���X�g���N�^                                                  */
/* �@�\�T�v :������                                                          */
/* ����     :raLine_Threshold_Value* :line_threshold_value  :�Q�Ɠn��        */
/* �߂�l   :�Ȃ�                                                            */
/* �쐬��   :2018/07/02   �b�c�@�[�N�@�@�@�V�K�쐬                           */
/* ------------------------------------------------------------------------- */
rnLine_Trace::rnLine_Trace(raLine_Threshold_Value& line_threshold_value)
				  /* ���C���������l�N���X�̃A�h���X�i�[ */
				: mraLine_Threshold_Value(line_threshold_value),
				  /* �o�����X���s�ɕK�v�Ȃ��̂����Z�b�g���邩���߂�ϐ� */
				  b_IsInitialized(false) {
}

/* ------------------------------------------------------------------------- */
/* �֐���   :LineTracing                                                     */
/* �@�\��   :���C���g���[�X                                                  */
/* �@�\�T�v :���C���g���[�X����B                                            */
/* ����     :�Ȃ�                                                            */
/* �߂�l   :SINT  :FUNC_OK  :����I��                                       */
/* �쐬��   :2018/07/02   �b�c�@�[�N�@�@�@�V�K�쐬                           */
/* ------------------------------------------------------------------------- */
SINT rnLine_Trace::LineTracing() {

	SINT i_color;                /* �������l�Z�b�g���\�b�h����̖߂�l�i�[�p */
	SINT i_direction;            /* ColorDirection���\�b�h����̖߂�l�i�[�p */

	class rnInverted_Control myrnInverted_Contro;      /* �|������Calss ���� */
				

	/* �o�����X���s�ɕK�v�Ȃ��̂����Z�b�g���邩�̃`�F�b�N */
	if (mIsInitialized == false) {
		myrnInverted_Control.Initialize();
		mIsInitialized = true;
	}

	/* ���C���������lClass�̂������l�Z�b�gMethod���Ă� */
	/* ���݂̃��C���̐F���擾 */
	i_color = mraLine_Threshold_Value->raLine_Threshold_Value_set();

	/* ���s�̂̌��������߂� */
	i_direction = ColorDirection(i_color);

	/* �|������Class��SetCommandMethod���Ă� */
	/* PWM�l��ݒ肷�� */
	myrnInverted_Control.SetCommand(rnInverted_Control::LOW, i_direction);

	/* �|�����s���s�� */
	myrnInverted_Control.Run();

	/* ���C���̐F���D�F���`�F�b�N */
	if (TS_GRAY == i_color)
	{
		return FUNC_OK;                              /* �D�F���������Ƃ�� */
	}
}


/* ------------------------------------------------------------------------- */
/* �֐���   :ColorDirection                                                  */
/* �@�\��   :�F�ɍ��������s���������߂�                                      */
/* �@�\�T�v :���C���̐F�𔻒f���đ��s������߂�l  �Ƃ��ĕԂ�                */
/* ����     :SINT  :i_color  :���݂̃��C���̐F                               */
/* �߂�l   :SINT  :rnInverted_Control::LOW   :���F or �D�F��������(LOW = 30)*/
/*          :      :-rnInverted_Control::LOW  :���F��������(-LOW = -30)      */
/* �쐬��   :2018/07/02   �b�c�@�[�N�@�@�@�V�K�쐬                           */
/* ------------------------------------------------------------------------- */
SINT rnLine_Trace::ColorDirection(SINT i_color) {

	/* ���݂̃��C���̐F�`�F�b�N */
	if (TS_BRACK == i_color) {                               /* ���C�����F */
			return rnInverted_Control::LOW;
	}
	else if (TS_WHITE == i_color)                            /* ���C�����F */
	{
			return -rnInverted_Control::LOW;
	}
	else if (TS_GRAY == i_color)                             /* ���C���D�F */
	{
			return rnInverted_Control::LOW;

	}

}

/* ------------------------------------------------------------------------- */
/*              Copyright HAL College of Technology & Design                 */
/* ------------------------------------------------------------------------- */

