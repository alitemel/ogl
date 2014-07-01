################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../src/3dof/joint.cpp \
../src/3dof/leg.cpp \
../src/3dof/pane.cpp \
../src/3dof/threeDof.cpp 

OBJS += \
./src/3dof/joint.o \
./src/3dof/leg.o \
./src/3dof/pane.o \
./src/3dof/threeDof.o 

CPP_DEPS += \
./src/3dof/joint.d \
./src/3dof/leg.d \
./src/3dof/pane.d \
./src/3dof/threeDof.d 


# Each subdirectory must supply rules for building sources it contributes
src/3dof/%.o: ../src/3dof/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -O0 -g3 -Wall -c -fmessage-length=0 -std=c++11 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


