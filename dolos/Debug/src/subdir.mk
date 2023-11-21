################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/dolos.cpp 

CPP_DEPS += \
./src/dolos.d 

OBJS += \
./src/dolos.o 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.cpp src/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/nazek/eclipse-workspace/dolos/src/bsl_commands" -I"/home/nazek/eclipse-workspace/dolos/Release/src/bsl_commands/bsl_command_response" -I"/home/nazek/eclipse-workspace/dolos/src/Utils" -I"/home/nazek/eclipse-workspace/dolos/src/Constants" -include"/home/nazek/eclipse-workspace/dolos/src/bsl_commands/BSLCommand.h" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


clean: clean-src

clean-src:
	-$(RM) ./src/dolos.d ./src/dolos.o

.PHONY: clean-src

