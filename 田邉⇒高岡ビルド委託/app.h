#ifdef __cplusplus
extern "C" {
#endif

#include "ev3api.h"

#define MAIN_PRIORITY    TMIN_APP_TPRI + 1

#ifndef TOPPERS_MACRO_ONLY

extern void main_task(intptr_t exinf);


#endif /* TOPPERS_MACRO_ONLY */

#ifdef __cplusplus
}
#endif

