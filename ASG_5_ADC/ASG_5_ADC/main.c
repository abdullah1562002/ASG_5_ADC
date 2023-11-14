/*
 * ASG_5_ADC.c
 *
 * Author : Abdullah Abdelgalel
 */ 

#define F_CPU 16000000UL
#include <util/delay.h>

// UTILITES
#include "STD_TYPES.h"
#include "BIT_MATH.h"


// MCAL
#include "ADC_interface.h"
#include "DIO_interface.h"

// HAL
#include "LCD_interface.h"



int main(void)
{

	// Potentiometer Pin
	DIO_setPinDirection(DIO_PORTA, DIO_PIN1, DIO_PIN_INPUT);
	
	// ADC Initialization
	ADC_init(ADC_REFERENCE_AVCC);
	
	// LED Initialization
	LCD_init();
	
	
	u16 digitalValue, analogValue;
	
    while (1) 
    {
		ADC_getDigitalValue(ADC_CHANNEL_1, &digitalValue); // Read ADC Value
		
		analogValue = ((u32)digitalValue * 5000) / 1024;   // Convert ADC Value to Analog (5000 millivolt is 5 volt)
		
		// Write Readed Voltage on The LCD and Update Every 1 sec
		LCD_writeString("Voltage :");
		LCD_writeNumber(analogValue);
		LCD_writeString("mv");
		_delay_ms(1000);
		LCD_clear();
		
    }
}


