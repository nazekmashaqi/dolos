################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/bsl_commands/BSLAck.cpp \
../src/bsl_commands/BSLCommand.cpp \
../src/bsl_commands/BSLCommandManager.cpp \
../src/bsl_commands/BSLConnection.cpp \
../src/bsl_commands/BSLFlashRangeErase.cpp \
../src/bsl_commands/BSLGetDeviceInfo.cpp \
../src/bsl_commands/BSLMassErase.cpp \
../src/bsl_commands/BSLMsg.cpp \
../src/bsl_commands/BSLRsp.cpp \
../src/bsl_commands/BSLStartApplication.cpp \
../src/bsl_commands/BSLUnlockBootloader.cpp 

CPP_DEPS += \
./src/bsl_commands/BSLAck.d \
./src/bsl_commands/BSLCommand.d \
./src/bsl_commands/BSLCommandManager.d \
./src/bsl_commands/BSLConnection.d \
./src/bsl_commands/BSLFlashRangeErase.d \
./src/bsl_commands/BSLGetDeviceInfo.d \
./src/bsl_commands/BSLMassErase.d \
./src/bsl_commands/BSLMsg.d \
./src/bsl_commands/BSLRsp.d \
./src/bsl_commands/BSLStartApplication.d \
./src/bsl_commands/BSLUnlockBootloader.d 

OBJS += \
./src/bsl_commands/BSLAck.o \
./src/bsl_commands/BSLCommand.o \
./src/bsl_commands/BSLCommandManager.o \
./src/bsl_commands/BSLConnection.o \
./src/bsl_commands/BSLFlashRangeErase.o \
./src/bsl_commands/BSLGetDeviceInfo.o \
./src/bsl_commands/BSLMassErase.o \
./src/bsl_commands/BSLMsg.o \
./src/bsl_commands/BSLRsp.o \
./src/bsl_commands/BSLStartApplication.o \
./src/bsl_commands/BSLUnlockBootloader.o 


# Each subdirectory must supply rules for building sources it contributes
src/bsl_commands/%.o: ../src/bsl_commands/%.cpp src/bsl_commands/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/nazek/eclipse-workspace/dolos/src/bsl_commands" -I"/home/nazek/eclipse-workspace/dolos/Release/src/bsl_commands/bsl_command_response" -I"/home/nazek/eclipse-workspace/dolos/src/Utils" -I"/home/nazek/eclipse-workspace/dolos/src/Constants" -include"/home/nazek/eclipse-workspace/dolos/src/bsl_commands/BSLCommand.h" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src-2f-bsl_commands

clean-src-2f-bsl_commands:
	-$(RM) ./src/bsl_commands/BSLAck.d ./src/bsl_commands/BSLAck.o ./src/bsl_commands/BSLCommand.d ./src/bsl_commands/BSLCommand.o ./src/bsl_commands/BSLCommandManager.d ./src/bsl_commands/BSLCommandManager.o ./src/bsl_commands/BSLConnection.d ./src/bsl_commands/BSLConnection.o ./src/bsl_commands/BSLFlashRangeErase.d ./src/bsl_commands/BSLFlashRangeErase.o ./src/bsl_commands/BSLGetDeviceInfo.d ./src/bsl_commands/BSLGetDeviceInfo.o ./src/bsl_commands/BSLMassErase.d ./src/bsl_commands/BSLMassErase.o ./src/bsl_commands/BSLMsg.d ./src/bsl_commands/BSLMsg.o ./src/bsl_commands/BSLRsp.d ./src/bsl_commands/BSLRsp.o ./src/bsl_commands/BSLStartApplication.d ./src/bsl_commands/BSLStartApplication.o ./src/bsl_commands/BSLUnlockBootloader.d ./src/bsl_commands/BSLUnlockBootloader.o

.PHONY: clean-src-2f-bsl_commands

