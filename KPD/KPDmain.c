#include "STD_TYPES.h"
#include "PORT_interface.h"
#include "DIO_interface.h"
#include "KEYPAD_interface.h"
#include "CLCD_interface.h"

//void calc(void);

void main (void)
{
	u8 Local_u8Key;
	PORT_voidInIt();
	CLCD_voidInit();
	volatile u32 Local_u32Op1 ,Local_u32Op2 ,Local_u32Oprand ,Local_u32Result;
	Local_u32Op1 = Local_u32Op2 = Local_u32Oprand = Local_u32Result = 0;
	while(1)
	{
		do
		{
			Local_u8Key = KEYPAD_u8GetPressedKey();
		}while(Local_u8Key == 18);

		if(Local_u8Key>=0 && Local_u8Key<=9)
		{
			CLCD_voidWriteNumber(Local_u8Key);
			/*checking if there is not any operation then store in op1*/
			if(Local_u32Oprand == 0)
			{
				Local_u32Op1*=10;
				Local_u32Op1 += Local_u8Key;
			}
			/*checking if there is an operation then store in op2*/
			else
			{
				Local_u32Op2*=10;
				Local_u32Op2 += Local_u8Key;
			}
		}
		else
		{
			Local_u32Oprand = Local_u8Key ;
			switch(Local_u8Key)
			{

			case '=':
				Local_u32Result = Local_u32Op1 + Local_u32Op2 ;
				CLCD_voidSendData('=');
				CLCD_voidWriteNumber(Local_u32Result);
				;break;
			case 'c':
				CLCD_voidClearScreen();
				/*set all the variables to zero to start a new operation*/
				Local_u32Op1 = Local_u32Op2 = Local_u32Oprand = Local_u32Result = 0;
				break;

			case '/':CLCD_voidSendData('/');break;
			case 'x':CLCD_voidSendData('x');break;
			case '-':CLCD_voidSendData('-');break;
			case '+':CLCD_voidSendData('+');break;

			}
		}
	}
}












//
//void calc(void)
//{
//switch(Local_u32Oprand)
//{
//case '/':
//	Local_u32Result = Local_u32Op1 / Local_u32Op2 ;
//	CLCD_voidSendData('=');
//	CLCD_voidWriteNumber(Local_u32Result);
//	break;
//case 'x':
//	Local_u32Result = Local_u32Op1 * Local_u32Op2 ;
//	CLCD_voidSendData('=');
//	CLCD_voidWriteNumber(Local_u32Result);
//	break;
//case '-':
//	Local_u32Result = Local_u32Op1 - Local_u32Op2 ;
//	CLCD_voidSendData('=');
//	CLCD_voidWriteNumber(Local_u32Result);
//	break;
//case '+':
//	Local_u32Result = Local_u32Op1 + Local_u32Op2 ;
//	CLCD_voidSendData('=');
//	CLCD_voidWriteNumber(Local_u32Result);
//	break;
//
//
//	if(Local_u32Oprand == '/')
//	{
//		Local_u32Result = Local_u32Op1 / Local_u32Op2 ;
//		CLCD_voidSendData('=');
//		CLCD_voidWriteNumber(Local_u32Result);
//	}
//	if(Local_u32Oprand == '*')
//	{
//		Local_u32Result = Local_u32Op1 * Local_u32Op2 ;
//		CLCD_voidSendData('=');
//		CLCD_voidWriteNumber(Local_u32Result);
//	}
//	if(Local_u32Oprand == '+')
//	{
//		Local_u32Result = Local_u32Op1 + Local_u32Op2 ;
//		CLCD_voidSendData('=');
//		CLCD_voidWriteNumber(Local_u32Result);
//	}
//	if(Local_u32Oprand == '-')
//	{
//		Local_u32Result = Local_u32Op1 - Local_u32Op2 ;
//		CLCD_voidSendData('=');
//		CLCD_voidWriteNumber(Local_u32Result);
//	}
//
//
//
//}
//}










