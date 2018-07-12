/* ------------------------------------------------------------------------- */
/*	rnInverted_Control.cpp                                                   */
/*	<EV3���C���g���[�X>�\�t�g�E�F�A�J��                                      */
/*	�|������N���X                                                           */
/*  �|�������S���B���s�p�v�Z�N���X�Ɍv�Z�w���𑗂�                         */
/*�@�߂�l�����[�^�[�o�͂ɑ���                                               */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	�ԍ�		�X�V����							���t		����		 */
/*	-----------------------------------------------------------------------  */
/*	000000		�V�K�쐬							2018/07/02	�c�  ����	 */
/* ------------------------------------------------------------------------- */

#include "rnInverted_Control.h"
/* ------------------------------------------------------------------------- */
/* �萔�錾                                                                  */
/* ------------------------------------------------------------------------- */
const SINT rnInverted_Control::LOW = 30;        /* �ᑬ                      */
const SINT rnInverted_Control::NORMAL = 50;     /* �ʏ�                      */
const SINT rnInverted_Control::HIGH = 70;       /* ����                      */

/* ------------------------------------------------------------------------- */
/*	�֐���		:rnInverted_Control                                          */
/*	�@�\��		:�|�����s�w��                                                */
/*	�@�\�T�v	:�|������E���s�̗���������A�e�N���X�Ɏw��������֐�        */
/*	����		:dgStattic_Angular_Velocity_get                              */
/*                              static_anglar_velocity_get                   */
/*								                �p���x�擾�N���X             */
/*			    :dgStatic_Motor_get                                          */
/*                              static_motor_get_left                        */
/*								                ���[�^�[�擾�N���X(��)       */
/*			    :dgStatic_Motor_get                                          */
/*                              static_motor_get_right                       */
/*								                ���[�^�[�擾�N���X(�E)       */
/*				:rnCalculation  calculation     ���s�p�v�Z�u�Ǘ��v�N���X     */
/*  �߂�l      :����                                                        */
/*	�쐬��		:2018/07/02		�c糎���		�V�K�쐬		�@�@�@		 */
/* ------------------------------------------------------------------------- */
rnInverted_Control::rnInverted_Control(const dgStattic_Angular_Velocity_get* static_anglar_velocity_get,
									   dgStatic_Motor_get* static_motor_get_left,
									   dgStatic_Motor_get* static_motor_get_right,
									   rnCalculation* calculation)
	: gyro_sensor(static_anglar_velocity_get),
	left_wheel(static_motor_get_left),
	right_wheel(static_motor_get_right),
	rn_calculation(calculation),
	i_forward(LOW),
	i_turn(LOW) {
}

/* ------------------------------------------------------------------------- */
/*	�֐���		:Run                                                         */
/*	�@�\��		:�|�����s�w��                                                */
/*	�@�\�T�v	:�|������E���s�̗���������A�e�N���X�Ɏw��������֐�        */
/*	����		:����                                                        */
/*  �߂�l      :����                                                        */
/*	�쐬��		:2018/07/02		�c糎���		�V�K�쐬		�@�@�@		 */
/* ------------------------------------------------------------------------- */
void rnInverted_Control::Run() {
	/* getInstance���Ăяo�� */
	class dgStattic_Angular_Velocity_get &gyro_sensor = dgStattic_Angular_Velocity_get::getInstance;
	/* �W���C���Z���T�l�擾 */
	SSHT s_angle = gyro_sensor->GyroGet();
	/* �E���[�^��]�p�x�擾 */
	SINT i_right_wheel_enc = right_wheel->RotationAngleGet();
	/* �����[�^��]�p�x�擾 */
	SINT i_left_wheel_enc = left_wheel->RotationAngleGet();

	/* rnCalculation�Ƀf�[�^��n�� */
	rn_calculation->SetCommand(i_forward, i_turn);

	/* �o�b�e���[�d���l���擾���� */
	SINT i_battery = dgStatic_Battery_Balance_Amount_Get->VoltageGet();

	/* ���E���[�^�[�o�͒l�𓾂� */
	rn_calculation->Update(s_angle, i_right_wheel_enc, i_left_wheel_enc, i_battery);

	/* ���E���[�^�ɉ�]���w������i�@����̊֐��҂��j */
	// dcMotor_Output->(rn_calculation->GetPwmLeft, rn_calculation->GetPwmright);
}

/* ------------------------------------------------------------------------- */
/*	�֐���		:Initialize                                                  */
/*	�@�\��		:�f�o�C�X������												 */
/*	�@�\�T�v	:�o�����X���s�ɕK�v�Ȑ��l�����Z�b�g����                      */
/*	����		:����                                                        */
/*  �߂�l      :����                                                        */
/*	�쐬��		:2018/07/02		�c糎���		�V�K�쐬		�@�@�@		 */
/* ------------------------------------------------------------------------- */
void rnInverted_Control::Initialize() {
	SINT i_offset = gyro_sensor->GyroGet();  // �W���C���Z���T�l

	/* ���[�^�G���R�[�_�����Z�b�g���� */
	//�@����̊֐��҂�
	/* dcMotor_Output->�֐���() */
	//left_wheel.reset();
	//right_wheel.reset();

	/* �|���U�q���䏉���� */
	rn_calculation->Initialize(i_offset);
}

/* ------------------------------------------------------------------------- */
/*	�֐���		:SetCommand                                                  */
/*	�@�\��		:PWM�ݒ�                                                     */
/*	�@�\�T�v	:���s�p�v�Z�ɓn���l��ݒ肷��                                */
/*	����		:SINT           forward         ��L�̒萔������(�O�i�l)     */
/*              :SINT           turn            ��L�̒萔������(����l)     */
/*  �߂�l      :����                                                        */
/*	�쐬��		:2018/07/02		�c糎���		�V�K�쐬		�@�@�@		 */
/* ------------------------------------------------------------------------- */
void rnInverted_Control::SetCommand(SINT forward, SINT turn) {
	i_forward = forward;
	i_turn = turn;
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
