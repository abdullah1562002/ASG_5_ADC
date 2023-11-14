/*
 * ADC_private.h
 *
 * Created: 10/7/2023 4:30:11 PM
 * Author : Abdullah Abdelgalel
 */ 


#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

									/*		ADC Registers		*/

// ADC Multiplexer Selection Register
#define ADMUX			(*(volatile u8*)0x27)
#define MUX0			0
#define MUX1			1
#define MUX2			2
#define MUX3			3
#define MUX4			4
#define ADLAR			5
#define REFS0			6
#define REFS1			7

// ADC Control and Status Register A
#define  ADCSRA			(*(volatile u8*)0x26)
#define  ADPS0			0
#define  ADPS1			1
#define  ADPS2			2
#define  ADIE			3
#define  ADIF			4
#define  ADATE			5
#define  ADSC			6
#define  ADEN			7

// The ADC Data Register
#define  ADC_u16		(*(volatile u16*)0x24)

// Special FunctionIO Register
#define  SFIOR			(*(volatile u8*)0x50)









#endif /* ADC_PRIVATE_H_ */