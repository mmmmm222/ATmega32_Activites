################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../DIO_programe.c \
../EXTI_proram.c \
../GIE_program.c \
../PORT_program.c \
../StepperMain.c 

OBJS += \
./DIO_programe.o \
./EXTI_proram.o \
./GIE_program.o \
./PORT_program.o \
./StepperMain.o 

C_DEPS += \
./DIO_programe.d \
./EXTI_proram.d \
./GIE_program.d \
./PORT_program.d \
./StepperMain.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


