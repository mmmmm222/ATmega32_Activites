/*
 * ADC_2_main.c
 *
 *  Created on: Mar 23, 2024
 *      Author: moali
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "PORT_interface.h"
#include "CLCD_interface.h"
#include "DIO_interface.h"
#include "GIE_interface.h"
#include "LM35_interface.h"
#include "ADC_interface.h"

void Display(void);

Chain_t Chain, *ptrChain;

u8 Channels[1]={0};
u16 Res[1];

void main(void)
{
	ptrChain->Channel = Channels;
	ptrChain->Size = 1;
	ptrChain->Result = Res;
	ptrChain->NotificationFunc = Display;

	PORT_voidInit();
	CLCD_voidInit();
	ADC_voidInit();
	GIE_VoidEnable();
	ADC_voidEnable();


	CLCD_voidSendString("Hello Boy");
	CLCD_voidSetPosition(CLCD_ROW_2,CLCD_COL_1);

	ADC_u8StartChainAsynch(&Chain);
	while(1)
	{
	}
}


void Display(void)
{
	static u32 C =0;
	C++;
	CLCD_voidSendNumber(C);
}
