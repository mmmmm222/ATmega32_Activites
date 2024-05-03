/*
 * ICU_1_main.c
 *
 *  Created on: May 2, 2024
 *      Author: moali
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "PORT_interface.h"
//#include "TIMER_interface.h"
//#include "EXTI_interface.h"
//#include "DIO_interface.h"
//#include "GIE_interface.h"
#include "CLCD_interface.h"
#include <util/delay.h>

void Response(void);

void main()
{
//	TIMER0_voidInit();
//	EXTI_u8SetCallBack(&Response);
//	EXTI_u8IntEnable(INT0);
//	TIMER1_voidInit();
	CLCD_voidInit();
//	GIE_voidEnable();


	while(1)
	{
		CLCD_voidGoToXY(0,0);
		CLCD_voidSendString("OCR1A value=");
	}
}

//void Response(void)
//{
//	static u16 cnt = 0, Period_Time , On_Time;
//	if(cnt == 0)
//	{
//		TIMER1_voidSetPreload(0);
//		cnt++;
//	}
//	else if(cnt == 1)
//	{
//		Period_Time = TIMER1_u16GetTimerCounterValue();
//		EXTI_u8Int0SetSenseCotrol(FALLING_EDGE);
//		cnt++;
//	}
//	else if(cnt == 2)
//	{
//		On_Time = (TIMER1_u16GetTimerCounterValue() - Period_Time);
//		cnt++;
//		EXTI_u8IntDisable(INT0);
//		CLCD_voidSendString("Period Time=");
//		CLCD_voidDisplayNumber(Period_Time);
//		CLCD_voidGoToXY(1,0);
//		CLCD_voidSendString("On Time=");
//		CLCD_voidDisplayNumber(On_Time);
//	}
//}
