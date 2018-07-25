mkfile_path := $(dir $(lastword $(MAKEFILE_LIST)))

APPL_COBJS +=\

APPL_CXXOBJS += \
dcMotor_Output.o\
dgMotor_Get.o\
rnInverted_Control.o\
rnLine_Trace.o

SRCLANG := c++

ifdef CONFIG_EV3RT_APPLICATION

# Include libraries
include $(EV3RT_SDK_LIB_DIR)/libcpp-ev3/Makefile

endif


APPL_DIR += $(mkfile_path)dcMotor_Output\
			$(mkfile_path)dgMotor_Get\
			$(mkfile_path)rnLine_Trace\
			$(mkfile_path)rnInverted_Control

INCLUDES += \
	-I$(mkfile_path)dcMotor_Output\
	-I$(mkfile_path)dgMotor_Get\
	-I$(mkfile_path)rnInverted_Control\
	-I$(mkfile_path)rnLine_Trace

COPTS += -fno-use-cxa-atexit
