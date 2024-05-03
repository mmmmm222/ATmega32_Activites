/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    ADC_rigister.h   >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author  : Mohamed Ali Saber
 *  Date    : 22/3/2024
 *  Version : V_1.00
 *  Layer   : MCAL
 *
 */

#ifndef ADC_REGISTER_H_
#define ADC_REGISTER_H_

#define ADMUX			*((volatile u8*)0x27)

//To select reference voltage
#define ADMUX_REFS1		7
#define	ADMUX_REFS0		6
#define	ADMUX_ADLAR		5				//left adjust => to use 8 bit reslution


#define ADCSRA			*((volatile u8*)0x26)
#define ADCSRA_ADEN    7                //ADC Enable
#define ADCSRA_ADSC    6                //ADC Start Conversion
#define	ADCSRA_ADATE   5                //ADC Auto Trigger Enable
#define	ADCSRA_ADIF    4				//ADC Interrupt Flag
#define	ADCSRA_ADIE    3                //ADC Interrupt Enable

/*These bits determine the division factor between the XTAL frequency and the input clock to the ADC*/
#define	ADCSRA_ADPS2   2                //ADC Prescaller Select Bit 2
#define	ADCSRA_ADPS1   1                //ADC Prescaller Select Bit 1
#define	ADCSRA_ADPS0   0                //ADC Prescaller Select Bit 0

//ADC Data Register => where the output of the conversion be found
#define ADCH	*((volatile u8*)0x25)
#define ADCL	*((volatile u8*)0x24)


#define SFIOR 			*((volatile u8*)0x50)
#define ADTS0			5
#define ADTS1			6
#define ADTS2			7


#endif
