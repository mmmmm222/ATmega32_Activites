/*
 * Servo_maic.c
 *
 *  Created on: Apr 28, 2024
 *      Author: moali
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "TIMER_register.h"
#include "ADC_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

void main(void){

	PORT_voidInIt();
	ADC_voidInit();
	CLCD_voidInit();

//	intialize timer choose fast pwm channel A
		SET_BIT(TCCR1A ,TCCR1A_COM1A1);
		CLR_BIT(TCCR1A ,TCCR1A_COM1A0);

		// mode 14
		CLR_BIT(TCCR1A , TCCR1A_WGM10);
		SET_BIT(TCCR1A , TCCR1A_WGM11);
		SET_BIT(TCCR1B , TCCR1B_WGM12);
		SET_BIT(TCCR1B , TCCR1B_WGM13);

		//prescaller
		TCCR1B &= 0b11111000;
		TCCR1B |= 0b00000010;

		// set icr1
		ICR1 = 20000;
		u16 res;
		while(1)
		{
			ADC_u8GetResultSync(0,&res);
			s32 conv = Map(0 , 1023 ,500 , 2000 , res);
			OCR1A = conv;
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendString("OCR1A value=");
			CLCD_voidDisplayNumber(conv);
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("ADC value=");
			CLCD_voidDisplayNumber(res);
			_delay_ms(150);
			CLCD_voidClearScreen();
		}

}
