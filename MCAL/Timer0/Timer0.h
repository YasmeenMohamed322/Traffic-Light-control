/*
 * Timer0_Private.h
 *
 * Created: 9/16/2022 11:26:59 PM
 *  Author: user
 */ 


#ifndef TIMER0_PRIVATE_H_
#define TIMER0_PRIVATE_H_
#include "../../registers.h"
#define TCCR0 *((volatile uint8_t*) 0x53)	
#define TCNT0 *((volatile uint8_t*) 0x52)	
#define TIMSK *((volatile uint8_t*) 0x59)	
#define TIFR0 *((volatile uint8_t*) 0x58)	
#define TOV0 0
#define CS00 0	
#define CS01 1	
#define CS02 2	
#define WGM01 3	
#define WGM00 6	
#define TIMER_ERROR 0
#define TIMER_OK 1
uint8_t Timer_delay(uint8_t sec);
#endif /* TIMER0_PRIVATE_H_ */