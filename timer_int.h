/*
 * timer_int.h
 *
 *  Created on: Sep 23, 2018
 *      Author: Dell
 */

#ifndef TIMER_INT_H_
#define TIMER_INT_H_
#include "../LIB/types.h"
#include "../LIB/math.h"
/**************TIMER0 INTERFACE**********/
#define FREQUENCY 12000000 //Frequency of the AVR
#define PRESCALLER 256 //check enum of prescaller
#define MODE 2 //check enum of mode
#define COMPARED_CAPTURE_VALUE 256 //for CTC mode to set the value of OCR0 it must be less than or equal 256
typedef enum en_timer_mode {
	Normal=0,
	CTC=1,
	FAST_PWM=2
}en_timer_mode;
typedef enum en_timer_prescaller{
	prescalling0=1,
	prescalling8=8,
	prescalling64=64,
	prescalling256=256,
	prescalling1024=1024,
	prescallingExternal=2000
}en_timer_prescaller;
typedef enum en_stateOf_OC0{ // enum for fn. return to check the process
	NotConnected=0,
	Toggle=1,//except pwm mode ,it is reserved.
	Clear=2,
	Set=3
}en_stateOf_OC0;
typedef enum en_return_flag{
	NoErrors=1,
	unexpected_input=1,
	NotAvailbleInThisMode=2,

};
u8 Timer0_Status(void);
/*******Description****************/
//for adjustment the timer mode and its prescaller
//return the process flag
// there is no argument
u8 Timer0_u8SetTime(u8 TimeDesired); //time in seconds
/*******Description****************/
//for adjustment the time , it differs from mode to another
//return No. of counts"No. of over flows" which after them you will get the desired time
// Argument=Desired time in seconds
u8 Timer0_u8PinOC0(en_stateOf_OC0 state);
/*******Description****************/
//for adjustment the OC0 pin which is B3
//return the process flag
// Argument:States of OC0 check its enum.
#endif /* TIMER_INT_H_ */
