#include "../../registers.h"
#include "../../Bit_calculations.h"
#include "EXI_Configuration.h"
#include "EXI_Interface.h"
#include "EXTI_private.h"
void (*callBackINT0)(void) = NULL;//assign the function to null at first
uint8_t EXT_INT0_Init(uint8_t INTSense)
{
	if(EXI_enable==Enable)
	SET(GICR,GICR_INT0);
	switch (INTSense)//switch case to know which interrupt sense will be used
	{
		case FALLING_EDGE:
		CLEAR(MCUCR,ISC00);
		SET(MCUCR,ISC01);
		break;
		case RISING_EDGE:
		SET(MCUCR, ISC00);
		SET(MCUCR, ISC01);
		case LOW_LEVEL:
		CLEAR (MCUCR, ISC00);
		CLEAR (MCUCR, ISC01);
		break;
		case Change:
		SET(MCUCR, ISC00);
		CLEAR(MCUCR, ISC01);
		break;
		default:
		return INT_ERROR;
	}
	return INT_OK;
}
void EXT_INT0_SETCallBack(void(*Fun)(void))
{
	callBackINT0 = Fun;
}
void __vector_1 (void) __attribute__ ((signal));
void __vector_1 (void)
{
	if (callBackINT0 != NULL)
	{
		callBackINT0();//if it is not equal null so the interrupt happens
	}
}