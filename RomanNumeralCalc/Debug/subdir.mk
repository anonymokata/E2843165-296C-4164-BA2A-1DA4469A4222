################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../checkSyntax.c \
../is_I_X_C-test.c 

O_SRCS += \
../checkSyntax.o \
../is_I_X_C-test.o 

OBJS += \
./checkSyntax.o \
./is_I_X_C-test.o 

C_DEPS += \
./checkSyntax.d \
./is_I_X_C-test.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


