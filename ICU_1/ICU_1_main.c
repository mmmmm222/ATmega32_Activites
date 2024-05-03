/*
 * ICU_1_main.c
 *
 *  Created on: May 2, 2024
 *      Author: moali
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
#include "TIMER_interface.h"
#include "EXTI_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "CLCD_interface.h"

void Response(void);

void main()
{
	PORT_voidInIt();
	EXTI_u8SetCallBack(&Response);
	EXTI_u8IntEnable(INT0);
	TIMER1_voidInit();
	CLCD_voidInit();
	TIMER0_voidInit();
	GIE_voidEnable();

	while(1)
	{
	}
}

void Response(void)
{
	static u16 cnt = 0, Period_Time , On_Time;
	if(cnt == 0)
	{
		TIMER1_voidSetPreload(0);
	}
	else if(cnt == 1)
	{
		EXTI_u8Int0SetSenseCotrol(FALLING_EDGE);
		Period_Time = TIMER1_u16GetTimerCounterValue();
	}
	else if(cnt == 2)
	{
		On_Time = (TIMER1_u16GetTimerCounterValue() );
		EXTI_u8IntDisable(INT0);
		CLCD_voidSendString("Period Time=");
		CLCD_voidDisplayNumber(Period_Time);
		CLCD_voidGoToXY(1,0);
		CLCD_voidSendString("On Time=");
		CLCD_voidDisplayNumber(On_Time);
	}
	cnt++;
}
