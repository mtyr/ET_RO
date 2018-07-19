mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS += \
rnCalculation.o \
balancer_param.o \

APPL_CXXOBJS += \
rnInverted_Control.o \
rnCalculation_Cpp.o \
dcMotor_Output.o \
dgAngular_Velocity_get.o \
dgBattery_Balance_Amount_get.o \
dgMotor_get.o \
rnCalculation_Cpp.o \



SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif
