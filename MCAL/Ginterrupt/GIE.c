
#include "../../registers.h"
#include "../../Bit_calculations.h"
#include "GIE_Interface.h"
#include "GIE_Private.h"
void GIE_Enable(void)
{
	SET(SREG,7);
}
void GIE_Disable(void)
{
	CLEAR(SREG,7);
}