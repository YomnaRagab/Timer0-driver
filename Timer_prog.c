/*
 * Timer_prog.c
 *
 *  Created on: Sep 23, 2018
 *      Author: Dell
 */
#include "../LIB/types.h"
#include "../LIB/math.h"
#include "locations.h"
#include "Timer_int.h"
u8 Timer0_Status(void)
{
	u8 flag;
	if(MODE==Normal)//Normal mode
	{
		TCCR0|=0b00000000;
		TIMSK=0x01;
		flag=NoErrors;
	}
	else if(MODE==CTC)//CTC mode
	{
		TCCR0|=0b00001000;
		TIMSK=0x01;
		flag=NoErrors;
	}
	else if(MODE==FAST_PWM)
	{
		TCCR0|=0b01001000;
		TIMSK=0x01;
		flag=NoErrors;
	}
	else
	{
		flag=unexpected_input;
	}
	switch (PRESCALLER)
	{
	case prescalling0:
		TCCR0|=0b00000001;
		break;
	case prescalling8:
		TCCR0|=0b00000010;
		break;
	case prescalling64:
		TCCR0|=0b00000011;
		break;
	case prescalling256:
		TCCR0|=0b00000100;
		break;
	case prescalling1024:
		TCCR0|=0b00000101;
		break;
	case prescallingExternal:
		TCCR0|=0b00000111;
		break;
	default:
		flag=unexpected_input;
		break;

	}
	return(flag);
}
u8 Timer0_u8SetTime(u8 TimeDesired)
{
	u8 count;
	if(MODE==Normal)
	{
	u8 TimerOV;
	TimerOV=(256000*PRESCALLER)/FREQUENCY; //multiplied by 1000 to take the first three decimal number after the point to set the TCNT0
	u8 No_Of_OV=((TimeDesired*10000)/TimerOV);
	TCNT0= 256-((((No_Of_OV)%10)*256)/10);
	count=(No_Of_OV/10)+1; //drop the first no. dividing by 10 and increase it by 1 to consider the fraction
}

	else if (MODE==CTC)
	{
		OCR0 =COMPARED_CAPTURE_VALUE;
		TIMSK=0b00000010;
		count=((TimeDesired)/((COMPARED_CAPTURE_VALUE*PRESCALLER)/FREQUENCY));
	}
	else
	{
		//error
	}
	return (count);
}
u8 Timer0_u8PinOC0(en_stateOf_OC0 state)
{
	TIMSK=0b00000010;
	u8 flag;
	switch(state)
	{
	case NotConnected:
		TCCR0|=0x00;
		break;
	case Toggle:
		if (MODE!=FAST_PWM)
		{
		TCCR0|=0b00010000;
		}
		else
		{
			flag=NotAvailbleInThisMode;
		}
		break;
	case Clear:
		TCCR0|=0b00100000;
		break;
	case Set:
		TCCR0|=0b00110000;
		break;
	default:
		flag=unexpected_input;
		break;
	}
	return(flag);
}
/************************TESTING*************************************/
/****************Normal mode with 1024 prescaller******************/
//#include "avr/interrupt.h"
//void main (void)
//{
//	SREG |= 0b10000000; //enable global int
//	DDRA=0x00;
//	PORTA=255;
//	DDRD=255;
//	Timer0_Status();
//	while(1)
//	{
//
//	}
//}
//ISR(TIMER0_OVF_vect)
//{
//
//	u8 counts= Timer0_u8SetTime(1);
//	static u8 i=0;
//	i++;
//		if((i==counts)&&(GET(PINA,0)==1))
//		{
//			i=0;
//			PORTD^=0x01;
//			counts= Timer0_u8SetTime(1);
//		}
//		if ((i==counts-20)&&(GET(PINA,0)==0))
//		{
//			i=0;
//			PORTD^=0x01;
//			counts= Timer0_u8SetTime(1);
//		}
//
//}
/****************FAST PWM mode with 256 prescaller & activate OC0 with Set mode******************/
#include "../../codes1/LIB/types.h"
#include "../../codes1/LIB/math.h"
#include "../../codes1/LIB/locations.h"
#include "avr/interrupt.h"
#define F_CPU 12000000
#include <avr/delay.h>

void main (void)
{
	 Timer0_Status();
	u8 i;
	DDRB=255;
	PORTB=0b00001000;
	Timer0_u8PinOC0(Set);
	while (1)
		{


			for(i=0; i<255; i++)
			{
				OCR0--;
				_delay_ms(10);
			}

}
}

