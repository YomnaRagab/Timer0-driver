#ifndef locations
#define locations

#define DDRA  *((volatile u8*)0X3A)
#define PORTA  *((volatile u8*)0X3B)
#define PINA  *((volatile u8*)0X39)
#define DDRB  *((volatile u8*)0X37)
#define PORTB  *((volatile u8*)0X38)
#define PINB  *((volatile u8*)0X36)
#define DDRC  *((volatile u8*)0X34)
#define PORTC  *((volatile u8*)0X35)
#define PINC  *((volatile u8*)0X33)
#define DDRD  *((volatile u8*)0X31)
#define PORTD  *((volatile u8*)0X32)
#define PIND  *((volatile u8*)0X30)
#define GICR  *((volatile u8*)0X5B)
#define TIMSK  *((volatile u8*)0X59)
#define TIFR  *((volatile u8*)0X58)
#define MCUCR  *((volatile u8*)0X55)
#define MCUCSR  *((volatile u8*)0X54)
#define TCCR0  *((volatile u8*)0X53)
#define TCNT0  *((volatile u8*)0X52)
#define TCCR1A  *((volatile u8*)0X4F)
#define TCCR1B  *((volatile u8*)0X4E)
#define TCNT1H  *((volatile u8*)0X4D)
#define TCNT1L  *((volatile u8*)0X4C)
#define ADMUX  *((volatile u8*)0X27)
#define ADCSRA  *((volatile u8*)0X26)
#define ADCH  *((volatile u8*)0X25)
#define ADCL  *((volatile u8*)0X25)
#define SREG *((volatile u8*)0X5F)
#define OCR0 *((volatile u8*)0X5C)
#endif
