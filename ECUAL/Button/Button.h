/*
 * Button.h
 *
 * Created: 9/9/2022 11:11:47 PM
 *  Author: user
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
#include "../../registers.h"
#include "../../MCAL/DIO/DIO.h"
#define NOtPressed 0
#define Pressed 1
void BUTTON_init(uint8_t buttonport,uint8_t buttonpin);
void BUTTON_read(uint8_t buttonport,uint8_t buttonpin,uint8_t *buttonvalue);
#endif /* BUTTON_H_ */