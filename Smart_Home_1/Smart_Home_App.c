/*
 * Smart_Home_App.c
 *
 *  Created on: Mar 2, 2024
 *      Author: moali
 */


#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "CLCD_interface.h"
#include "ADC_interface.h"
#include "LM35_interface.h"
#include "util/delay.h"

void Get_Pass(void);

// The password for the home
u8 Global_u8Svaed_Pass[4] = "1234";

void main (void)
{
	PORT_voidInIt();
	CLCD_voidInit();
	ADC_voidInit();
	ADC_voidEnable();

	CLCD_voidSendString(" WELCOME BACK");
	_delay_ms(1000);
	Get_Pass();

	while(1)
	{
	}
}


void Get_Pass(void)
{
	u8 Local_u8PassCnt =4,Local_u8Counter , Local_u8EnteredPassArray[4] ={0} , Local_u8Flag=0 ,Local_u8Key=0;
	static u8 Local_u8Tries=3;
	CLCD_voidClearScreen();
	CLCD_voidSendString(" ENTER PASSWORD");
	CLCD_voidGoToXY(1,0);
	for(Local_u8Counter=0; Local_u8Counter < Local_u8PassCnt; Local_u8Counter++)
	{
		do
		{
			Local_u8Key = KEYPAD_u8GetPressedKey();
		}while(Local_u8Key == 18);
		CLCD_voidSendString("*");
		Local_u8EnteredPassArray[Local_u8Counter] = Local_u8Key;
		if(Local_u8EnteredPassArray[Local_u8Counter] != Global_u8Svaed_Pass[Local_u8Counter])
		{
			Local_u8Flag =1;
		}
	}
	if(Local_u8Flag == 1)
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString(" WRONG PASSWORD");
		Local_u8Tries--;
		_delay_ms(1000);
		if(Local_u8Tries !=0)
		{
			CLCD_voidClearScreen();
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendString("   TRY AGAIN");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("YOU HAVE ");
			CLCD_voidDisplayNumber(Local_u8Tries);
			CLCD_voidSendString(" TRIES");
			_delay_ms(1000);
			Get_Pass();
		}
		else if(Local_u8Tries == 0)
		{
			CLCD_voidClearScreen();
			CLCD_voidGoToXY(0,0);
			CLCD_voidSendString("YOU HAVE NO MORE");
			CLCD_voidGoToXY(1,0);
			CLCD_voidSendString("     TRIES    ");
		}
	}
	else
	{
		CLCD_voidClearScreen();
		CLCD_voidSendString("CORRECT PASSWORD");

	}

}
