/*
 * LED.c
 *
 * Created: 9/9/2022 10:49:00 PM
 *  Author: user
 */ 
#include "LED.h"
uint8_t LED_init(uint8_t ledport,uint8_t ledpin)
{
	//calling DIO_init function to initialize the LED
	if(DIO_init(ledport,ledpin,OUT)==DIO_OK)
	return LED_OK;
	else
	return LED_ERROR;
}
uint8_t LED_on(uint8_t ledport,uint8_t ledpin)
{
	//calling DIO_write function to turn on the LED and set its state to high
	if(DIO_write(ledport,ledpin,HIGH)==DIO_OK)
	return LED_OK;
	else
	return LED_ERROR;
}
uint8_t LED_off(uint8_t ledport,uint8_t ledpin)
{
	//calling DIO_write function to turn off the LED and set its state to low
	if(DIO_write(ledport,ledpin,LOW)==DIO_OK)
	return LED_OK;
	else
	return LED_ERROR;
	//DIO_write(ledport,ledpin,LOW);
}
uint8_t LED_toggle(uint8_t ledport,uint8_t ledpin)
{
	//calling DIO_toggle function to toggle the led
	if(DIO_toggle(ledport,ledpin)==DIO_OK)
	return LED_OK;
	else
	return LED_ERROR;
}