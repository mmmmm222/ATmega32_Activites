################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_program.c \
../DIO_programe.c \
../PORT_program.c \
../USART_main.c \
../USART_program.c 

OBJS += \
./CLCD_program.o \
./DIO_programe.o \
./PORT_program.o \
./USART_main.o \
./USART_program.o 

C_DEPS += \
./CLCD_program.d \
./DIO_programe.d \
./PORT_program.d \
./USART_main.d \
./USART_program.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@)" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


