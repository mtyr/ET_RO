#ifndef DGMOTOR_GET_H_
#define DGMOTOR_GET_H_

#include "common.h"

class dgMotor_get{

public:
	dgMotor_get();
	static dgMotor_get& GetInstance(void);
	I32T RotationAngleGet();
	void reset();

private:
};

#endif // ! DGMOTOR_GET_H_
