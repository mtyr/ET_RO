/*	-----------------------------------------------------------------------  */
/*	rnInverted_Control.h                                                     */
/*	<EV3���C���g���[�X>�\�t�g�E�F�A�J��                                      */
/*	�|�������S��                                                           */
/*																			 */
/*	-----------------------------------------------------------------------  */
/*	�ԍ�		�X�V����							���t		����		 */
/*	-----------------------------------------------------------------------  */
/*	000000		�V�K�쐬							2018/07/02	�c�  ����	 */
/*	-----------------------------------------------------------------------  */

#ifndef RNINVERTED_CONTROL_H_
#define RNINVERTED_CONTROL_H_

#include "common.h"								/* �R�[�f�B���O�K��          */
#include "rnCalculation.h"						/* �v�Z�w��                  */
#include "dgStatic_Angular_Velocity_Get.h"		/* �f�o�C�X�擾�i�W���C���j  */
#include "dgStatic_Battery_Balance_Amount_get.h"/* �f�o�C�X�擾�i�o�b�e���[�j*/
#include "dgStatic_Motor_get.h"		            /* �f�o�C�X�擾�i���[�^�[�j�@*/

class rnInverted_Control {
public:
	static const SINT LOW;
	static const SINT NORMAL;
	static const SINT HIGH;

	rnInverted_Control(const dgStattic_Angular_Velocity_get* static_anglar_velocity_get,
					   dgStatic_Motor_get* static_motor_get_left,
					   dgStatic_Motor_get* static_motor_get_right,
					   rnCalculation* calculation);

	void Initialize();
	void Run();
	void SetCommand(SINT forward, SINT turn);

private:
	const dgStattic_Angular_Velocity_get* gyro_sensor;
	dgStatic_Motor_get* left_wheel;
	dgStatic_Motor_get* right_wheel;
	rnCalculation* rn_calculation;
	SINT i_forward;
	SINT i_turn;
};

#endif  // RNINVERTED_CONTROL_H_

/*	-----------------------------------------------------------------------	 */
/*				Copyright HAL College of Technology & Design				 */
/*	-----------------------------------------------------------------------	 */
