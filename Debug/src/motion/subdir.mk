################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/motion/calcJointAngles.cpp \
../src/motion/calcPosition.cpp \
../src/motion/motion.cpp 

OBJS += \
./src/motion/calcJointAngles.o \
./src/motion/calcPosition.o \
./src/motion/motion.o 

CPP_DEPS += \
./src/motion/calcJointAngles.d \
./src/motion/calcPosition.d \
./src/motion/motion.d 


# Each subdirectory must supply rules for building sources it contributes
src/motion/%.o: ../src/motion/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


