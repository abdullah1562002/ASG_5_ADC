/*
 * ADC_interface.h
 *
 * Created: 10/7/2023 4:29:52 PM
 * Author : Abdullah Abdelgalel
 */ 


#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#define ADC_CHANNEL_0		0
#define ADC_CHANNEL_1		1
#define ADC_CHANNEL_2		2
#define ADC_CHANNEL_3		3
#define ADC_CHANNEL_4		4
#define ADC_CHANNEL_5		5
#define ADC_CHANNEL_6		6
#define ADC_CHANNEL_7		7

#define ADC_REFERENCE_AVCC			1
#define ADC_REFERENCE_AREF			2
#define ADC_REFERENCE_INTERNAL		3


void ADC_init(u8 referenceVolt);
void ADC_getDigitalValue(u8 channelID,u16 * returnedValue);



#endif /* ADC_INTERFACE_H_ */