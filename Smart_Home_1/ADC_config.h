/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_config.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 22/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_


/*select reference voltage

  Options :
 	- AVCC
  	- AREF
 	- INTERNAL

 */
#define VREF	AVCC

/*select the presentation of the ADC conversion result

  Options :

 	- LEFT_ADJUST
 	- RIGHT_ADJUST

 */
#define ADC_ADJUSTMENT	RIGHT_ADJUST

/*select the prescaler

  Options :

    - ADC_PRE_2
	- ADC_PRE_4
	- ADC_PRE_8
	- ADC_PRE_16
	- ADC_PRE_32
	- ADC_PRE_64
	- ADC_PRE_128

 */

#define ADC_PRESCALLER 	ADC_PRE_2

/*select the Channel

  Options :

    - ADC0
	- ADC1
	- ADC2
	- ADC3
	- ADC4
	- ADC5
	- ADC6T
    - ADC7
 */

#define Channel_Gain	ADC0

#define ADC_STATE	ADC_ENABLE

#define INT_STATUS  INT_DISABLE


/* select the Trigger Source

  Options :

  	- Singel_Conversion
	- Free_Running_mode
	- Analog_Comparator
	- External_Interrupt_Request
	- Timer/Counter0_Compare_Match
	- Timer_Counter0_Overflow
	- Timer_Counter_Compare_Match_B
	- Timer_Counter1_Overflow
	- Timer_Counter1_Capture_Event

*/

#define ADC_TRIGGERING_SOURCE	Free_Running_mode




#endif
