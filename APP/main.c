/*
 * main.c
 *
 *  Created on: Apr 7, 2020
 *      Author: hp
 */
#include "../LIBRARY/stdTypes.h"
#include "../LIBRARY/BIT_MATH.h"
#include "../LIBRARY/errorStates.h"
#include "../LIBRARY/AVR_REG.h"

#include "../MCAL/GIE_int.h"
#include "../MCAL/ADC_int.h"
#include <util/delay.h>

void adc (void*);
volatile u8 adcRead;
u8 a= 10;
void* ptr= &a;
int main ()
{
	ADC_enuInit();
 	DDRB=0xff;
	DDRA=0x00;
	GIE_enuEnable();
	ADC_enuEnable();
	ADC_enuSelectChannel(0);
	ADC_enuEnableInterrupt();
	ADC_enuDisableTrigger();
	ADC_enuCallBackFunction(adc ,ptr);
		//ADC_enuStartConversion();
	while (1)
	{
		ADC_enuStartConversion();
		//ADC_enuPollingOnFlag();

	}

	return 0;
}

void adc (void*f)
{
	u8 * pty;
	pty=(u8*)f;
	//ADC_enuReadHighRegister(&adcRead);
	//PORTB=adcRead;
	PORTB=*pty;
	//ADC_enuStartConversion();
	//PORTB|=(1<<7);
	(*pty)++;
}

