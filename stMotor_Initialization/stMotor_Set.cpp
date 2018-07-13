/*	------------------------------------------------------------------------ */
/*	stMotor.cpp															   	 */
/*	ET-���{�R��																 */
/*	���������ɒl��n���N���X												 */
/*	-----------------------------------------------------------------------	 */
/*	�ԍ�	�X�V����								���t		����		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	�V�K�쐬								2018/07/09	�L�{�@�А^�@ */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	include	�t�@�C��														 */
/*	-----------------------------------------------------------------------	 */
#include "common.h"
#include "stMotor_Set.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*	-----------------------------------------------------------------------	 */
/*	�R���X�g���N�^															 */
/*	-----------------------------------------------------------------------	 */
stMotor_Initialization::stMotor_Initialization()
{

}

/*	-----------------------------------------------------------------------	 */
/*	�f�X�g���N�^															 */
/*	-----------------------------------------------------------------------	 */
stMotor_Initialization::~stMotor_Initialization()
{
	
}

/* ------------------------------------------------------------------------- */
/* ������ public ������														 */
/* ------------------------------------------------------------------------- */

/*	-----------------------------------------------------------------------	 */
/*	public�֐���	:MotorMeasurement										 */
/*	�@�\��			:���[�^�[�v��											 */
/*	�@�\�T�v		:�e���[�^�[�̗V�є͈͂̒l��n��							 */
/*	����			:SINT               : L									 */
/*                  :                   : R                                  */
/*                  :                   : T                                  */
/*	�߂�l			:int				: FUNC_OK	:�֐�����I��			 */
/*					:					: FUNC_ERR	:�֐��ُ�I��			 */
/*	�쐬��			:2018/07/09		 �L�{�@�А^  	             �V�K�쐬	 */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::MotorMeasurement(I08T *Max,
	SINT *L,SINT *R,SINT *T)
{
	MaxMotorMeasurement(Max);
	LGearPlayRange(L);
	RGearPlayRange(R);
	TailGearPlayRange(T);
	return FUNC_OK;
}

/* ------------------------------------------------------------------------- */
/* ������ private ������													 */
/* ------------------------------------------------------------------------- */

/*	---------------------------------------------------------------------- - */
/*	public�֐���	:MaxMotorMeasurement									 */
/*	�@�\��			:Max���[�^�[�v��										 */
/*	�@�\�T�v		:���[�^�[��Max�̒l��n��								 */
/*	����			:SINT 				: L									 */
/*	�߂�l			:int				: FUNC_OK	:�֐�����I��			 */
/*					:					: FUNC_ERR	:�֐��ُ�I��			 */
/*	�쐬��			:2018/07/10		 �L�{�@�А^ 				 �V�K�쐬	 */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::MaxMotorMeasurement(I08T *Max)
{
	I08T MaxL = 100;                                      /* �����[�^�[Max�l */
	I08T MaxR = 100;                                      /* �E���[�^�[Max�l */
	class dcMotor_Output dcM;                        /* dcMotor_Output���̉� */
	dcM.Motor_Output(MaxL,MaxR);
	/* MaxL��MaxR���l���Ⴉ�����ꍇ                                        */
	if (MaxL<MaxR)
	{
		*Max = MaxL;
	}
	/* MaxR��MaxL���l���Ⴉ�����ꍇ                                        */
	else if (MaxR<MaxL){
		*Max = MaxR;
	}
	return FUNC_OK;
}
/*	---------------------------------------------------------------------- - */
/*	public�֐���	:LGearPlayRange											 */
/*	�@�\��			:���M�A�V�є͈͌v��										 */
/*	�@�\�T�v		:���M�A�̗V�є͈͒l��n��								 */
/*	����			:SINT 				: LGearPlayRangevalue				 */
/*	�߂�l			:int				: FUNC_OK	:�֐�����I��			 */
/*					:					: FUNC_ERR	:�֐��ُ�I��			 */
/*	�쐬��			:2018/07/10		 �L�{�@�А^ 				 �V�K�쐬	 */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::LGearPlayRange(SINT *LGearPlayRangevalue)
{
	*LGearPlayRangevalue = 4;						   /* ���M�A�̗V�є͈͒l */
	return FUNC_OK;
}

/*	---------------------------------------------------------------------- - */
/*	public�֐���	:RGearPlayRange											 */
/*	�@�\��			:�E�M�A�V�є͈͌v��										 */
/*	�@�\�T�v		:�E�M�A�̗V�є͈͒l��n��								 */
/*	����			:SINT 				: RGearPlayRangevalue				 */
/*	�߂�l			:int				: FUNC_OK	:�֐�����I��			 */
/*					:					: FUNC_ERR	:�֐��ُ�I��			 */
/*	�쐬��			:2018/07/10		 �L�{�@�А^ 				 �V�K�쐬	 */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::RGearPlayRange(SINT *RGearPlayRangevalue)
{
	*RGearPlayRangevalue = 4;						   /* �E�M�A�̗V�є͈͒l */
	return FUNC_OK;
}

/*	---------------------------------------------------------------------- - */
/*	public�֐���	:TailGearPlayRange										 */
/*	�@�\��			:�K���M�A�V�є͈͌v��									 */
/*	�@�\�T�v		:�K���M�A�̗V�є͈͒l��n��								 */
/*	����			:SINT 				: TailGearPlayRangevalue			 */
/*	�߂�l			:int				: FUNC_OK	:�֐�����I��			 */
/*					:					: FUNC_ERR	:�֐��ُ�I��			 */
/*	�쐬��			:2018/07/10		 �L�{�@�А^ 				 �V�K�쐬	 */
/*	-----------------------------------------------------------------------	 */
SINT stMotor_Initialization::TailGearPlayRange(SINT *TailGearPlayRangevalue)
{
	*TailGearPlayRangevalue = 4;					 /* �K���M�A�̗V�є͈͒l */
	return FUNC_OK;
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */