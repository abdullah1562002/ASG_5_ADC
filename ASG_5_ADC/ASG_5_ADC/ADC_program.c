/*
 * ADC_program.c
 *
 * Created: 10/7/2023 4:29:35 PM
 * Author : Abdullah Abdelgalel
 */ 

/*UTILITIES*/
#include "BIT_MATH.h"
#include "STD_TYPES.h"


/*MCAL*/
#include "ADC_interface.h"
#include "ADC_private.h"



void ADC_init(u8 referenceVolt)
{
	switch (referenceVolt)
	{
		case ADC_REFERENCE_AVCC:
			SET_BIT(ADMUX, REFS0);
			CLR_BIT(ADMUX, REFS1);
		break;
		
		case ADC_REFERENCE_AREF:
			CLR_BIT(ADMUX, REFS0);
			CLR_BIT(ADMUX, REFS1);
		break;
		
		case ADC_REFERENCE_INTERNAL:
			SET_BIT(ADMUX, REFS0);
			SET_BIT(ADMUX, REFS1);
		break;
	}
	
	// SELECT RIGHT ADJUST
	CLR_BIT(ADMUX, ADLAR);
	
	// SINGLE CONVERSION MODE
	CLR_BIT(ADCSRA,ADATE);
	
	// DISABLE ADC INTERRUPT
	CLR_BIT(ADCSRA, ADIE);
	
	// PRESCALAR 128 for 16MHZ (125KHZ)
	SET_BIT(ADCSRA,ADPS0);
	SET_BIT(ADCSRA,ADPS1);
	SET_BIT(ADCSRA,ADPS2);
	
	// ADC ENABLE
	SET_BIT(ADCSRA,ADEN);
}

void ADC_getDigitalValue(u8 channelID,u16 * returnedValue)
{
	if ((returnedValue != NULL) && (channelID<32))
	{
			// SELECT CHANNEL
			
			// CLEAR ADMUX CHANNEL BITS
			ADMUX &= 0xE0;
			
			// SELECT CHANNEL NUMBER
			ADMUX |= channelID;
			
			// START CONVERSION
			SET_BIT(ADCSRA,ADSC);
			
			// MONITOR ADC FLAG
			while (0 == GET_BIT(ADCSRA,ADIF));
			
			// CLEAR FLAG(write one to clear)
			SET_BIT(ADCSRA,ADIF);
			
			// Return Digital Data (from data register)
			*returnedValue = ADC_u16;
			
			
	}
}