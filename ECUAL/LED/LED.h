/*
 * LED.h
 *
 * Created: 9/9/2022 10:49:28 PM
 *  Author: user
 */ 


#ifndef LED_H_
#define LED_H_
#include "../../registers.h"
#include "../../MCAL/DIO/DIO.h"//upper layers calls lower layers
#define LED_ERROR 0
#define LED_OK 1
uint8_t LED_init(uint8_t ledport,uint8_t ledpin);
uint8_t LED_on(uint8_t ledport,uint8_t ledpin);
uint8_t LED_off(uint8_t ledport,uint8_t ledpin);
uint8_t LED_toggle(uint8_t ledport,uint8_t ledpin);

#endif /* LED_H_ */