/* ------------------------------------------------------------------------- */
/*	rnCalculation_Cpp.h                                                      */
/*	<EV3���C���g���[�X>�\�t�g�E�F�A�J��                                      */
/*	���s�p�v�Z���s�N���X                                                     */
/*  ���[�^�[�o�͒l���v�Z����                                                 */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	�ԍ�		�X�V����							���t		����		 */
/*	-----------------------------------------------------------------------  */
/*	000000		�V�K�쐬							2018/07/11	�c�  ����	 */
/* ------------------------------------------------------------------------- */

/* ------------------------------------------------------------------------- */
/*�T�v  : 2�֌^�|���U�q���{�b�g�uNXTway-GS�v�o�����X����v���O����
          NXTway-GS�̃o�����X����ɂ́A�T�[�{����(��� + �ϕ��t�B�[�h�o�b�N)
          �Ƃ������㐧���K�p���Ă��܂��B����Ώۂ̓��肨��ѐ����̊J��
          �ɂ�The MathWorks�Ђ�MATLAB&Simulink�Ƃ������i���g�p�����A
          MBD(���f���x�[�X�f�U�C��/�J��)�J����@��p���Ă��܂��B����C�v���O������
          Simulink���f������Real-Time Workshop Embedded Coder�R�[�h�����W���@�\��
          �g�p���Ď����������ꂽ���̂ł��B�o�����X�����̐���p�����[�^�ɂ��Ă�
          ���[�U�[�n���h�R�[�h���Œ�`����K�v������܂��B��`��Ƃ��āA
          nxtOSEK\samples\nxtway_gs\balancer_param.c���Q�Ƃ��Ă��������B
          �o�����X����A���S���Y���̏ڍ׏��ɂ��܂��Ă�
          ���{��: http://www.cybernet.co.jp/matlab/library/library/detail.php?id=TA060
          �p��  : http://www.mathworks.com/matlabcentral/fileexchange/loadFile.do?objectId=19147&objectType=file
          ���Q�Ƃ��Ă��������B
*/
/* ------------------------------------------------------------------------- */



#include "rnCalculation.h"
#include "balancer_private.h"

/*============================================================================
 * Local macro definitions
 *===========================================================================*/
#define rt_SATURATE(sig,ll,ul)         (((sig) >= (ul)) ? (ul) : (((sig) <= (ll)) ? (ll) : (sig)) )

/*============================================================================
 * Data definitions
 *===========================================================================*/
static FLOT ud_err_theta;          /* ���E�ԗւ̕��ω�]�p�x(��)�ڕW�덷��Ԓl */
static FLOT ud_psi;                /* �ԑ̃s�b�`�p�x(��)��Ԓl */
static FLOT ud_theta_lpf;          /* ���E�ԗւ̕��ω�]�p�x(��)��Ԓl */
static FLOT ud_theta_ref;          /* ���E�ԗւ̖ڕW���ω�]�p�x(��)��Ԓl */
static FLOT ud_thetadot_cmd_lpf;   /* ���E�ԗւ̖ڕW���ω�]�p���x(d��/dt)��Ԓl */

/*============================================================================
 * Functions
 *===========================================================================*/
//*****************************************************************************
// �֐���  : balance_control
// ����    :
//   (float)args_cmd_forward : �O�i/��i���߁B100(�O�i�ő�l)�`-100(��i�ő�l)
//   (float)args_cmd_turn    : ���񖽗߁B100(�E����ő�l)�`-100(������ő�l)
//   (float)args_gyro        : �W���C���Z���T�l
//   (float)args_gyro_offset : �W���C���Z���T�I�t�Z�b�g�l
//   (float)args_theta_m_l   : �����[�^�G���R�[�_�l
//   (float)args_theta_m_r   : �E���[�^�G���R�[�_�l
//   (float)args_battery     : �o�b�e���d���l(mV)
// �߂�l  :
//   (char*)ret_pwm_l        : �����[�^PWM�o�͒l
//   (char*)ret_pwm_r        : �E���[�^PWM�o�͒l
// �T�v    :  NXTway-GS�o�����X����֐��B
//            ���̊֐���4msec�����ŋN������邱�Ƃ�O��ɐ݌v����Ă��܂��B
//            �Ȃ��A�W���C���Z���T�I�t�Z�b�g�l�̓Z���T�̂���ђʓd�ɂ��h���t�g
//            �𔺂��܂��̂ŁA�K�X�␳����K�v������܂��B�܂��A���E�̎ԗ֋쓮
//            ���[�^�͌̍��ɂ��A����PWM�o�͂�^���Ă���]�����قȂ�ꍇ��
//            ����܂��B���̏ꍇ�͕ʓr�␳�@�\��ǉ�����K�v������܂��B
// �g�p��  :
//        /* �ō������i���� */
//        balance_control(
//          (float)100,                                  /* �O�i�ō������� */
//          (float)0,                                    /* �����񖽗� */
//          (float)ecrobot_get_gyro_sensor(NXT_PORT_S4), /* �W���C���Z���T�l */
//          (float)605,                                  /* �ԑ̒�~���̃W���C���Z���T�l */
//          (float)nxt_motor_get_count(NXT_PORT_C),      /* �����[�^�G���R�[�_�l */
//          (float)nxt_motor_get_count(NXT_PORT_B),      /* �E���[�^�G���R�[�_�l */
//          (float)ecrobot_get_battery_voltage(),        /* �o�b�e���d���l(mV) */
//          &pwm_l,                                    /* �����[�^PWM�o�͒l */
//          &pwm_r);                                   /* �E���[�^PWM�o�͒l */
//*****************************************************************************
void Calculation_Control(float args_cmd_forward, float args_cmd_turn, float
                     args_gyro, float args_gyro_offset, float
                     args_theta_m_l, float args_theta_m_r, float
                     args_battery, signed char *ret_pwm_l, signed char *ret_pwm_r)
{
  {
    FLOT tmp_theta;
	FLOT tmp_theta_lpf;
	FLOT tmp_pwm_r_limiter;
	FLOT tmp_psidot;
	FLOT tmp_pwm_turn;
	FLOT tmp_pwm_l_limiter;
	FLOT tmp_thetadot_cmd_lpf;
	FLOT tmp[4];
	FLOT tmp_theta_0[4];
	SLNG tmp_0;

    /* Sum: '<S8>/Sum' incorporates:
     *  Constant: '<S3>/Constant6'
     *  Constant: '<S8>/Constant'
     *  Constant: '<S8>/Constant1'
     *  Gain: '<S3>/Gain1'
     *  Gain: '<S8>/Gain2'
     *  Inport: '<Root>/cmd_forward'
     *  Product: '<S3>/Divide'
     *  Product: '<S8>/Product'
     *  Sum: '<S8>/Sum1'
     *  UnitDelay: '<S8>/Unit Delay'
     */
    tmp_thetadot_cmd_lpf = (((args_cmd_forward / CMD_MAX) * K_THETADOT) * (1.0F
      - A_R)) + (A_R * ud_thetadot_cmd_lpf);

    /* Gain: '<S4>/Gain' incorporates:
     *  Gain: '<S4>/deg2rad'
     *  Gain: '<S4>/deg2rad1'
     *  Inport: '<Root>/theta_m_l'
     *  Inport: '<Root>/theta_m_r'
     *  Sum: '<S4>/Sum1'
     *  Sum: '<S4>/Sum4'
     *  Sum: '<S4>/Sum6'
     *  UnitDelay: '<S10>/Unit Delay'
     */
    tmp_theta = (((DEG2RAD * args_theta_m_l) + ud_psi) + ((DEG2RAD *
      args_theta_m_r) + ud_psi)) * 0.5F;

    /* Sum: '<S11>/Sum' incorporates:
     *  Constant: '<S11>/Constant'
     *  Constant: '<S11>/Constant1'
     *  Gain: '<S11>/Gain2'
     *  Product: '<S11>/Product'
     *  Sum: '<S11>/Sum1'
     *  UnitDelay: '<S11>/Unit Delay'
     */
    tmp_theta_lpf = ((1.0F - A_D) * tmp_theta) + (A_D * ud_theta_lpf);

    /* Gain: '<S4>/deg2rad2' incorporates:
     *  Inport: '<Root>/gyro'
     *  Inport: '<Root>/gyro_offset'
     *  Sum: '<S4>/Sum2'
     */
    tmp_psidot = (args_gyro - args_gyro_offset) * DEG2RAD;

    /* Gain: '<S2>/Gain' incorporates:
     *  Constant: '<S3>/Constant2'
     *  Constant: '<S3>/Constant3'
     *  Constant: '<S6>/Constant'
     *  Constant: '<S9>/Constant'
     *  Gain: '<S1>/FeedbackGain'
     *  Gain: '<S1>/IntegralGain'
     *  Gain: '<S6>/Gain3'
     *  Inport: '<Root>/battery'
     *  Product: '<S2>/Product'
     *  Product: '<S9>/Product'
     *  Sum: '<S1>/Sum2'
     *  Sum: '<S1>/sum_err'
     *  Sum: '<S6>/Sum2'
     *  Sum: '<S9>/Sum'
     *  UnitDelay: '<S10>/Unit Delay'
     *  UnitDelay: '<S11>/Unit Delay'
     *  UnitDelay: '<S5>/Unit Delay'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    tmp[0] = ud_theta_ref;
    tmp[1] = 0.0F;
    tmp[2] = tmp_thetadot_cmd_lpf;
    tmp[3] = 0.0F;
    tmp_theta_0[0] = tmp_theta;
    tmp_theta_0[1] = ud_psi;
    tmp_theta_0[2] = (tmp_theta_lpf - ud_theta_lpf) / EXEC_PERIOD;
    tmp_theta_0[3] = tmp_psidot;
    tmp_pwm_r_limiter = 0.0F;
    for (tmp_0 = 0; tmp_0 < 4; tmp_0++) {
      tmp_pwm_r_limiter += (tmp[tmp_0] - tmp_theta_0[tmp_0]) * K_F[(tmp_0)];
    }

    tmp_pwm_r_limiter = (((K_I * ud_err_theta) + tmp_pwm_r_limiter) /
                         ((BATTERY_GAIN * args_battery) - BATTERY_OFFSET)) *
      100.0F;

    /* Gain: '<S3>/Gain2' incorporates:
     *  Constant: '<S3>/Constant1'
     *  Inport: '<Root>/cmd_turn'
     *  Product: '<S3>/Divide1'
     */
    tmp_pwm_turn = (args_cmd_turn / CMD_MAX) * K_PHIDOT;

    /* Sum: '<S2>/Sum' */
    tmp_pwm_l_limiter = tmp_pwm_r_limiter + tmp_pwm_turn;

    /* Saturate: '<S2>/pwm_l_limiter' */
    tmp_pwm_l_limiter = rt_SATURATE(tmp_pwm_l_limiter, -100.0F, 100.0F);

    /* Outport: '<Root>/pwm_l' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion'
     */
    (*ret_pwm_l) = (signed char)tmp_pwm_l_limiter;

    /* Sum: '<S2>/Sum1' */
    tmp_pwm_r_limiter -= tmp_pwm_turn;

    /* Saturate: '<S2>/pwm_r_limiter' */
    tmp_pwm_r_limiter = rt_SATURATE(tmp_pwm_r_limiter, -100.0F, 100.0F);

    /* Outport: '<Root>/pwm_r' incorporates:
     *  DataTypeConversion: '<S1>/Data Type Conversion6'
     */
    (*ret_pwm_r) = (signed char)tmp_pwm_r_limiter;

    /* Sum: '<S7>/Sum' incorporates:
     *  Gain: '<S7>/Gain'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    tmp_pwm_l_limiter = (EXEC_PERIOD * tmp_thetadot_cmd_lpf) + ud_theta_ref;

    /* Sum: '<S10>/Sum' incorporates:
     *  Gain: '<S10>/Gain'
     *  UnitDelay: '<S10>/Unit Delay'
     */
    tmp_pwm_turn = (EXEC_PERIOD * tmp_psidot) + ud_psi;

    /* Sum: '<S5>/Sum' incorporates:
     *  Gain: '<S5>/Gain'
     *  Sum: '<S1>/Sum1'
     *  UnitDelay: '<S5>/Unit Delay'
     *  UnitDelay: '<S7>/Unit Delay'
     */
    tmp_pwm_r_limiter = ((ud_theta_ref - tmp_theta) * EXEC_PERIOD) +
      ud_err_theta;

    /* user code (Update function Body) */
    /* System '<Root>' */
    /* ���񉉎Z�p��ԗʕۑ����� */

    /* Update for UnitDelay: '<S5>/Unit Delay' */
    ud_err_theta = tmp_pwm_r_limiter;

    /* Update for UnitDelay: '<S7>/Unit Delay' */
    ud_theta_ref = tmp_pwm_l_limiter;

    /* Update for UnitDelay: '<S8>/Unit Delay' */
    ud_thetadot_cmd_lpf = tmp_thetadot_cmd_lpf;

    /* Update for UnitDelay: '<S10>/Unit Delay' */
    ud_psi = tmp_pwm_turn;

    /* Update for UnitDelay: '<S11>/Unit Delay' */
    ud_theta_lpf = tmp_theta_lpf;
  }
}

//*****************************************************************************
// �֐���  : Calculation_Initialize
// ����    : ����
// �߂�l  : ����
// �T�v    : NXTway-GS�o�����X���䏉�����֐��B������ԗʕϐ������������܂��B
//           ���̊֐��ɂ��o�����X����@�\������������ꍇ�́A�����č��E��
//           �ԗ֋쓮���[�^�[�̃G���R�[�_�l��0�Ƀ��Z�b�g���Ă��������B
// �g�p��  :
//		nxt_motor_set_speed(NXT_PORT_C, 0, 1); /* �����[�^��~ */
//		nxt_motor_set_speed(NXT_PORT_B, 0, 1); /* �E���[�^��~ */
//		balance_init();						   /* NXTway-GS�o�����X���䏉���� */
//      /* ���[�^�G���R�[�_�l��0���Z�b�g����O�Ƀ��[�^����~���Ă��邱�� */
//		nxt_motor_set_count(NXT_PORT_C, 0);    /* �����[�^�G���R�[�_0���Z�b�g */
//		nxt_motor_set_count(NXT_PORT_B, 0);    /* �E���[�^�G���R�[�_0���Z�b�g */
//*****************************************************************************
void Calculation_Initialize(void)
{
  /* Registration code */

  /* states (dwork) */

  /* custom states */
  ud_err_theta = 0.0F;
  ud_theta_ref = 0.0F;
  ud_thetadot_cmd_lpf = 0.0F;
  ud_psi = 0.0F;
  ud_theta_lpf = 0.0F;
}

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */