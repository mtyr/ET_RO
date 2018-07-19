#ifndef DGBATTERY_BALANCE_AMOUNT_GET_H
#define DGBATTERY_BALANCE_AMOUNT_GET_H

#include "common.h"

class dgBattery_Balance_Amount_get{

public:
	dgBattery_Balance_Amount_get();
	static dgBattery_Balance_Amount_get& GetInstance();
	I32T VoltageGet();
private:
};

#endif