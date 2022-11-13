/*
 * Button.c
 *
 * Created: 9/9/2022 11:12:01 PM
 *  Author: user
 */ 
#include "Button.h"
void BUTTON_init(uint8_t buttonport,uint8_t buttonpin)
{
	DIO_init(buttonport,buttonpin,IN);
}
void BUTTON_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *buttonvalue)
{
	DIO_read(buttonport,buttonpin,buttonvalue);
}