################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DIO_programe.c \
../KEYPAD_program.c \
../KPDmain.c \
../PORT_program.c 

OBJS += \
./CLCD_program.o \
./DIO_programe.o \
./KEYPAD_program.o \
./KPDmain.o \
./PORT_program.o 

C_DEPS += \
./CLCD_program.d \
./DIO_programe.d \
./KEYPAD_program.d \
./KPDmain.d \
./PORT_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


