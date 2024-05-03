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


void main (void)
{
	u8 Local_u8Key, password[6]={1,0,2,0,3,0}, entry[10],i=0,counter=0;
	u16 ANALOG =10,Temp;
	PORT_voidInIt();
	CLCD_voidInit();
	ADC_voidInit();
	ADC_voidEnable();


	while(1)
	{

		do
		{
			Local_u8Key = KEYPAD_u8GetPressedKey();
		}while(Local_u8Key == 18);


		if((Local_u8Key>=0 && Local_u8Key<=9) || Local_u8Key== '=')
		{
			if(Local_u8Key == '=')
			{
				CLCD_voidGoToXY(1,0);
				CLCD_voidSendString("                ");
				CLCD_voidGoToXY(1,0);

				if(i>6)
				{
					CLCD_voidGoToXY(0,0);
					CLCD_voidSendString("                ");
					CLCD_voidGoToXY(0,0);
					CLCD_voidSendString("Wrong Password");
				}

				else
				{
					for(i=0; i<6; i++)
					{
						// check the equality of the password
						if(password[i] == entry[i])
						{
							counter++;
						}

						else
						{
							CLCD_voidGoToXY(0,0);
							CLCD_voidSendString("                ");
							CLCD_voidGoToXY(0,0);
							CLCD_voidSendString("Wrong Password");
							return;
						}

					}
				}

				if(counter==6)
				{
					CLCD_voidGoToXY(0,0);
					CLCD_voidSendString("                ");
					CLCD_voidGoToXY(0,0);
					CLCD_voidSendString("Welcome Home");
					CLCD_voidGoToXY(0,0);
					CLCD_voidSendString("                ");

					while(1)
					{
						ADC_u8GetResultSync(0,&ANALOG);
						//						DIO_u8SetPortValue(DIO_u8PORTC,ANALOG);
						//						CLCD_voidDisplayNumber(ANALOG);
						CLCD_voidGoToXY(1,0);
						CLCD_voidSendString("temp = ");
						LM35_voidTempratureReading(ANALOG,&Temp);
						CLCD_voidDisplayNumber(Temp);

					}
				}
			}

			else
			{
				entry[i] = Local_u8Key;
				i++;
				CLCD_voidDisplayNumber(Local_u8Key);
			}
		}


	}

}




/*

 * */
