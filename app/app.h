/*
 * app.h
 *
 * Created: 9/12/2022 3:07:36 AM
 *  Author: user
 */ 


#ifndef APP_H_
#define APP_H_
#include "../MCAL/DIO/DIO.h"
#define Cars PORT_A
#define Cars_GREEN_LED 0  
#define Cars_YELLOW_LED 1 
#define Cars_RED_LED 2
#define pedestrians PORT_B
#define pedestrians_GREEN_LED 0
#define pedestrians_YELLOW_LED 1
#define pedestrians_RED_LED 2
//#define Button PORT_D
//#define Button_Pin 2
void APP_Init(void);
void APP_Start(void);//normal mode
void INT0_ISR(void);//pedestrian mode
#endif /* APP_H_ */