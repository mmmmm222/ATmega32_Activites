/*
 * WDT_main.c
 *
 *  Created on: May 3, 2024
 *      Author: moali
 */


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "DIO_interface.h"
#include "util/delay.h"




#define WDTCR 				(*(volatile u8*)0x41)
#define WDTCR_EDTOE			4
#define WDTCR_WDE			3
#define WDTCR_WDP2			2
#define WDTCR_WDP1			1
#define WDTCR_WDP0			0

void WDT_voidSleep(u8 Copy_u8SleepTime)
{
	WDTCR &= 0b11111000;
	WDTCR |= Copy_u8SleepTime;
}
void WDT_voidDisable(void)
{
	SET_BIT(WDTCR , WDTCR_WDE);
}

void WDT_voidEnable(void)
{
	// sequence of disabling the wdt
	WDTCR |= 0b00011000;
	WDTCR = 0;

}

void main(void)
{
	PORT_voidInIt();

	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_HIGH);
	_delay_ms(1000);
	DIO_u8SetPinValue(DIO_u8PORTA,DIO_u8PIN0,DIO_u8PIN_LOW);

	WDT_voidEnable();
	WDT_voidSleep(6);
	WDT_voidDisable();

	while(1)
	{

	}

}
