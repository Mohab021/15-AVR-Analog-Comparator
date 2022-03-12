
#include <avr/io.h>
#define F_CPU 4000000UL
#include "AVR_Analog_Comparator.h"

void AC_AIN1_Initialize()
{
	//taking negative input from AIN1 (disable ADC negative input)
	
	SFIOR &= !(1<<ACME); //clearing ACME bit (write 0 to it)
	ACSR = 0x00; //clear ACSR (write 0 to all of the bits)
}

void AC_ADC_Initialize()
{
	//taking negative input from ADC (disable AIN1 negative input)
	
	ADCSRA &= !(1<<ADEN); //clearing ADEN bit (write 0 to it) to disable ADC function
	
	ADMUX = 0x00; //clearing ADMUX, using ADC0 (MUX2..0 = 000)
	SFIOR |= (1<<ACME); //set ACME bit (write 1 to it)
	ACSR = 0x00; //clear ACSR (write 0 to all of the bits)
}
