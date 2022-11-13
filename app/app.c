
#include "../MCAL/DIO/DIO.h"
#include "../MCAL/Ginterrupt/GIE_Interface.h"
#include "../MCAL/Ginterrupt/GIE_Private.h"
#include "../MCAL/EXinterrupt/EXI_Interface.h"
#include "../MCAL/EXinterrupt/EXTI_private.h"
#include "../MCAL/EXinterrupt/EXI_Configuration.h"
#include "../ECUAL/Button/Button.h"
#include "../ECUAL/LED/LED.h"
#include "app.h"
#include "../MCAL/Timer0/Timer0.h"
#include "../Bit_calculations.h"
void APP_Init(void)
{
	LED_init(Cars,Cars_GREEN_LED);
	LED_init(Cars,Cars_YELLOW_LED);
	LED_init(Cars,Cars_RED_LED);
	LED_init(pedestrians,pedestrians_GREEN_LED);
	LED_init(pedestrians,pedestrians_YELLOW_LED);
	LED_init(pedestrians,pedestrians_RED_LED);
	//BUTTON_init(Button,Button_Pin);
	GIE_Enable();
   EXT_INT0_Init(RISING_EDGE);
   EXT_INT0_SETCallBack(&INT0_ISR);
}
void APP_Start(void)
{
	//Normal mode
	uint8_t val,redled,greenled,yellowled;
	//BUTTON_read(Button,Button_Pin,&val);
	DIO_read(Cars,Cars_RED_LED,&redled);
	DIO_read(Cars,Cars_GREEN_LED,&greenled);
	DIO_read(Cars,Cars_YELLOW_LED,&yellowled);
		LED_on(Cars,Cars_GREEN_LED);
		Timer_delay(5);
		LED_off(Cars,Cars_GREEN_LED);
		for (uint8_t i= 0;i<5;i++)
		{
			LED_toggle(Cars,Cars_YELLOW_LED);
			Timer_delay(1);
		}
		LED_off(Cars,Cars_YELLOW_LED);
		LED_on(Cars,Cars_RED_LED);
		Timer_delay(5);
		LED_off(Cars,Cars_RED_LED);
		for (uint8_t i= 0;i<5;i++)
		{
			LED_toggle(Cars,Cars_YELLOW_LED);
			Timer_delay(1);
		}
		LED_off(Cars,Cars_YELLOW_LED);
}
void INT0_ISR()
{
	//pedestrian mode
	uint8_t val,redled,greenled,yellowled;
	//BUTTON_read(Button,Button_Pin,&val);
	DIO_read(Cars,Cars_RED_LED,&redled);
	DIO_read(Cars,Cars_GREEN_LED,&greenled);
	DIO_read(Cars,Cars_YELLOW_LED,&yellowled);
		LED_off(pedestrians,pedestrians_RED_LED);
		if (redled==HIGH)
		{
			LED_on(pedestrians,pedestrians_GREEN_LED);
			LED_on(Cars,Cars_RED_LED);
			Timer_delay(5);
			LED_off(Cars,Cars_RED_LED);
		}
		else if(yellowled==HIGH)
		{
			LED_on(Cars,Cars_YELLOW_LED);
			LED_on(pedestrians,pedestrians_YELLOW_LED);
			for (uint8_t i= 0;i<5;i++)
			{
				LED_toggle(Cars,Cars_YELLOW_LED);
				LED_toggle(pedestrians,pedestrians_YELLOW_LED);
				Timer_delay(1);
			}
			yellowled=LOW;
			LED_off(Cars,Cars_YELLOW_LED);
			LED_off(pedestrians,pedestrians_YELLOW_LED);
			LED_on(pedestrians,pedestrians_GREEN_LED);
			LED_on(Cars,Cars_RED_LED);
			Timer_delay(5);
			LED_off(Cars,Cars_RED_LED);
		}
		else if (greenled==HIGH)
		{
				LED_on(pedestrians,pedestrians_RED_LED);
				Timer_delay(5);
				LED_off(pedestrians,pedestrians_RED_LED);
				LED_off(Cars,Cars_GREEN_LED);
		
			LED_off(pedestrians,pedestrians_YELLOW_LED);
			LED_off(Cars,Cars_YELLOW_LED);
			for (uint8_t i= 0;i<5;i++)
			{
				yellowled=HIGH;
				LED_toggle(Cars,Cars_YELLOW_LED);
				LED_toggle(pedestrians,pedestrians_YELLOW_LED);
				Timer_delay(1);
			}
			yellowled=LOW;
			LED_off(Cars,Cars_YELLOW_LED);
			LED_off(pedestrians,pedestrians_YELLOW_LED);
			LED_on(pedestrians,pedestrians_GREEN_LED);
			LED_on(Cars,Cars_RED_LED);
			Timer_delay(5);
			LED_off(Cars,Cars_RED_LED);
		}
		
		LED_off(pedestrians,pedestrians_GREEN_LED);
		LED_off(pedestrians,pedestrians_RED_LED);
}
