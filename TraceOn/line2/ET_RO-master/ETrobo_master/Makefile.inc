mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=\
balancer_param.o\
rnCalculation.o



APPL_CXXOBJS += \
crDriving_Order.o\
crStart_Preparation.o\
dcMotor_Output.o\
dcTail_Motor_Output.o\
dgAngular_Velocity_Get.o\
dgBattery_Balance_Amount_Get.o\
dgColor_Get.o\
dgMotor_Get.o\
dgUltrasonic_Wave_Get.o\
frBluetooth.o\
frLog.o\
raLine_Threshold_Value.o\
raMotor_Setting_Value.o\
rnCalculation_Cpp.o\
rnLine_Trace.o\
stGyro_Set.o\
stLine_Threshold_Value_Set.o\
stMotor_Initialization.o\
rnInverted_Control.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif


APPL_DIR += $(mkfile_path)frLog\
			$(mkfile_path)frBluetooth\
			$(mkfile_path)crDriving_Order\
			$(mkfile_path)crStart_Preparation\
			$(mkfile_path)dcMotor_Output\
			$(mkfile_path)dcTail_Motor_Output\
			$(mkfile_path)dgAngular_Velocity_Get\
			$(mkfile_path)dgBattery_Balance_Amount_Get\
			$(mkfile_path)dgColor_Get\
			$(mkfile_path)dgMotor_Get\
			$(mkfile_path)dgUltrasonic_Wave_Get\
			$(mkfile_path)raLine_Threshold_Value\
			$(mkfile_path)raMotor_Setting_Value\
			$(mkfile_path)rnCalculation\
			$(mkfile_path)rnCalculation_Cpp\
			$(mkfile_path)rnLine_Trace\
			$(mkfile_path)stGyro_Set\
			$(mkfile_path)stLine_Threshold_Value_Set\
			$(mkfile_path)stMotor_Initialization\
			$(mkfile_path)rnInverted_Control

INCLUDES += \
	-I$(mkfile_path)frLog\
	-I$(mkfile_path)frBluetooth\
	-I$(mkfile_path)crDriving_Order\
	-I$(mkfile_path)crStart_Preparation\
	-I$(mkfile_path)dcMotor_Output\
	-I$(mkfile_path)dcTail_Motor_Output\
	-I$(mkfile_path)dgAngular_Velocity_Get\
	-I$(mkfile_path)dgBattery_Balance_Amount_Get\
	-I$(mkfile_path)dgColor_Get\
	-I$(mkfile_path)dgMotor_Get\
	-I$(mkfile_path)dgUltrasonic_Wave_Get\
	-I$(mkfile_path)raLine_Threshold_Value\
	-I$(mkfile_path)raMotor_Setting_Value\
	-I$(mkfile_path)rnCalculation\
	-I$(mkfile_path)rnCalculation_Cpp\
	-I$(mkfile_path)rnLine_Trace\
	-I$(mkfile_path)stGyro_Set\
	-I$(mkfile_path)stLine_Threshold_Value_Set\
	-I$(mkfile_path)stMotor_Initialization\
	-I$(mkfile_path)rnInverted_Control

COPTS += -fno-use-cxa-atexit
