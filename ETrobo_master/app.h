#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"
	

#define MAIN_PRIORITY    TMIN_APP_TPRI + 1

#ifndef STACK_SIZE
#define STACK_SIZE      4096
#endif /* STACK_SIZE */

#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);
	
/*	�f�o�C�X�n���h��	*/
extern void dc_cyc(intptr_t unused);

/*	Bluetooth��M�����n���h��	*/
extern void dt_cyc(intptr_t unused);

#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif
