/*
 * EXI_Interface.h
 *
 * Created: 9/11/2022 1:33:41 PM
 *  Author: user
 */ 


#ifndef EXI_INTERFACE_H_
#define EXI_INTERFACE_H_
#include "../../registers.h"
#define INT_ERROR 0
#define INT_OK 1
uint8_t EXT_INT0_Init(uint8_t INTSense);
//ISR
void EXT_INT0_SETCallBack(void(*Fun)(void));
 void INT0_VECT(void) __attribute__((signal));
#endif /* EXI_INTERFACE_H_ */