
#define F_CPU 4000000UL
#include <util/delay.h>
#include <avr/io.h>
#include "AVR_Ports.h"
#include "AVR_LCD_Declarations.h"
#include "AVR_Analog_Comparator.h"

int main(void)
{
	Pin_Direction(C, 6, output);
	Pin_Direction(C, 7, output);
	Pin_Reset(C, 6);
	Pin_Reset(C, 7);
	
	LCD_Initialize();
	AC_AIN1_Initialize();
	//AC_ADC_Initialize();
	
	_delay_ms(100);
	
	while(1)
	{
		if( ACSR & (1<<ACO) ) //AIN0 is higher (+ve R)
		{
			Pin_Set(C, 6);
			Pin_Reset(C, 7);
			LCD_Print("R+ ");
			_delay_ms(10);
		
		while( ACSR & (1<<ACO) ) ; //stay here until comparator status is changed
		}
		else //AIN1/ADC0 is higher (-ve R)
		{
			Pin_Set(C, 7);
			Pin_Reset(C, 6);
			LCD_Print("R- ");
			_delay_ms(10);
			
		while( !(ACSR & (1<<ACO)) ) ; //stay here until comparator status is changed
		}
	}
}
