/*	------------------------------------------------------------------------ */
/*	stGyro_Set.cpp														   	 */
/*	ET-���{�R��																 */
/*	���������ɃW���C���Z���T�[�̒l�̃Z�b�g���w������N���X					 */
/*	-----------------------------------------------------------------------	 */
/*	�ԍ�	�X�V����								���t		����		 */
/*	-----------------------------------------------------------------------	 */
/*	000000	�V�K�쐬								2018/06/26	�F�s�{�@���� */
/*	-----------------------------------------------------------------------	 */

/*	-----------------------------------------------------------------------	 */
/*	include	�t�@�C��														 */
/*	-----------------------------------------------------------------------	 */
#include"stGyro_Set.h"

/*	-----------------------------------------------------------------------	 */
/*	�R���X�g���N�^															 */
/*	-----------------------------------------------------------------------	 */
stGyro_Set::stGyro_Set(){

}

/*	-----------------------------------------------------------------------	 */
/*	�f�X�g���N�^															 */
/*	-----------------------------------------------------------------------	 */
stGyro_Set::~stGyro_Set(){

}

/*	-----------------------------------------------------------------------	 */
/*	public�֐���	:OffsetStart											 */
/*	�@�\��			:�W���C���Z���T�[�̃I�t�Z�b�g���J�n����					 */
/*	�@�\�T�v		:IN�t�H���_�̎w�肳�ꂽ�摜��ǂݍ���					 */
/*	����			:����													 */
/*	�߂�l			:int				:FUNC_OK	:�֐�����I��			 */
/*					:					:FUNC_ERR	:�֐��ُ�I��			 */
/*	�쐬��			:2018/06/26		 �F�s�{�@����				 �V�K�쐬	 */
/*	-----------------------------------------------------------------------	 */
SINT stGyro_Set::OffSetStart(){
	SINT i_gyro_set = 0;
	SINT i_loop = 0;
	/* �W���C���Z���T�[�̒l���󂯎�� */
	class dgStatic_Angular_Velocity_Get GyroGet;
	while (i_loop == 0){
		i_gyro_set = GyroGet.GyroGet();
		if (i_gyro_set != FUNC_ERR){
			/* �G���[���̂݃��[�v�𑱂��� */
			i_loop = 1;
		}
	}
}