/**************************************************************************/
/*******************    Author : Mohammed Ali Saber  **********************/
/*******************    Layer  : MCAL                **********************/
/*******************    Component: EXTI              **********************/
/*******************    version : 1.00               **********************/
/*******************    date : 28/1/20234            **********************/
/**************************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"


void EXTI_voidInt0Init(void)
{
	/*set sense CTRL for INT0 to falling edge*/
	SET_BIT(MCUCR,MCUCR_ISC01);
	CLR_BIT(MCUCR,MCUCR_ISC00);

	/* Peripheral interrupt enable for INT0*/
	SET_BIT(GICR,GICR_INT0);
}
