/* ------------------------------------------------------------------------- */
/*	rnCalculation_Cpp.h                                                      */
/*	<EV3���C���g���[�X>�\�t�g�E�F�A�J��                                      */
/*  ���s�p�v�Z�Ǘ��N���X                                                     */
/*	�|������N���X����̎w���ő��s�p�v�Z���Ǘ�����                           */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	�ԍ�		�X�V����							���t		����		 */
/*	-----------------------------------------------------------------------  */
/*	000000		�V�K�쐬							2018/07/11	�c�  ����	 */
/* ------------------------------------------------------------------------- */

#ifndef EV3_UNIT_CALCULATION_CPP_H_
#define EV3_UNIT_CALCULATION_CPP_H_

#include "cstdint"
#include "common.h"								/* �R�[�f�B���O�K��          */

class rnCalculation {
public:
	rnCalculation();

	void Initialize(SINT offset);
    void Update(SINT angle, SINT rwEnc, SINT lwEnc, SINT battery);
    void SetCommand(SINT forward, SINT turn);
    int8_t GetPwmRight();
    int8_t GetPwmLeft();

private:
    SINT CancelBacklash(int8_t pwm, SINT enc);

    SINT i_forward;
    SINT i_turn;
    SINT i_offset;
    int8_t i_right_pwm;
    int8_t i_left_pwm;
};

#endif  // EV3_UNIT_CALCULATION_CPP_H_

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
