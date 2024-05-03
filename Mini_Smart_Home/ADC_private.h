/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_private.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 22/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

/*select reference voltage*/

#define AREF			     				0b00000000
#define AVCC			     				0b01000000
#define INTERNAL_2_56		 				0b11000000

/* Adjust Representation*/

#define LEFT_ADJUST		     				0b00100000
#define RIGHT_ADJUST		 				0b00000000

/*prescaler*/

#define ADC_PRE_2	 		 				0b00000000
#define ADC_PRE_4     		 				0b00000010
#define ADC_PRE_8     		 				0b00000011
#define ADC_PRE_16     		 				0b00000100
#define ADC_PRE_32     			 			0b00000101
#define ADC_PRE_64     		 				0b00000110
#define ADC_PRE_128     	 				0b00000111

#define ADC_PRE_MASK				 		0b11111000


/* Analog Channel and Gain S election Bits */
/* Single Ended Input */
#define ADC_CHANNEL0		 				0b00000000
#define ADC_CHANNEL1    	 				0b00000001
#define ADC_CHANNEL2    	 				0b00000010
#define ADC_CHANNEL3    	 				0b00000011
#define ADC_CHANNEL4    	 				0b00000100
#define ADC_CHANNEL5    	 				0b00000101
#define ADC_CHANNEL6    	 				0b00000110
#define ADC_CHANNEL7    	 				0b00000111

#define ADC_CHANNEL_MASK	 				0b11111000

/* Differential Input */


/* ADC State enabled or disabled */
#define ADC_ENABLE							0b10000000
#define ADC_DISABLE			 				0b00000000


/* ADC Start Conversion */
#define ADC_START_CONVERSION				0b01000000

/* ADC Auto Trigger Enable */
#define ADC_AUTO_TRIGGER					0b00100000


/* ADC Interrupt Enable */
#define INT_DISABLE             			0b00000000
#define INT_ENABLE              			0b00001000

/*need to implement the interrupt flag*/

#define Singel_Conversion					0b00000001
#define Free_Running_mode					0b00000000
#define Analog_Comparator                   0b00100000
#define External_Interrupt_Request          0b01000000
#define Timer_Counter0_Compare_Match        0b01100000
#define Timer_Counter0_Overflow             0b10000000
#define Timer_Counter_Compare_Match_B       0b10100000
#define Timer_Counter1_Overflow             0b11000000
#define Timer_Counter1_Capture_Event        0b11100000




#define IDEL								1
#define BUSY								2
#define TIMEOUT								3
#define SINGLE_CHANNEL_ASYNCH				4
#define CHAIN_CHANNEL_ASYNCH				5
#define ADC_TIME_OUT 						5000

#endif
