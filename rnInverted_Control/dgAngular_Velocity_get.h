#ifndef DGANGULAR_VELOCITY_GET_G_
#define DGANGULAR_VELOCITY_GET_G_

#include "common.h"								/* �R�[�f�B���O�K��          */

class dgAngular_Velocity_get{
public:
	dgAngular_Velocity_get();
	static dgAngular_Velocity_get& GetInstance(void);
	I32T GyroGet();
private:


};

#endif // !DGANGULAR_VELOCITY_GET_G_
