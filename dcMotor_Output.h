#include "BalancingWalker.h"
#include "BalancerCpp.h"
#include "Motor.h"
#include "ev3api.h"
#include "app.h"


class dcMotor_Output{
	
	public:
	void MotorOutput(int8_t getPwmLeft,int8_t getPwmRight);
	
	private:
	Balancer* mBalancer;
	int8_t mRightPwm;
    int8_t mLeftPwm;

};
