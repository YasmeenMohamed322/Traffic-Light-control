#include "../../Bit_calculations.h"
#include "Timer0.h"
#define F_CPU 1000000U

	uint8_t Timer_delay(uint8_t sec)
	{
		if(sec>0)
		{
		float OVF = ((sec)/( (1.0/F_CPU)*256));//OVF=delay req/max delay & max delay=2^8*tick& tick=prescaler/f_cpu
		float OVF_count = 0;
		TCCR0 = 0x00;// normal mode
		TCNT0 = 0x00;// initial value=0
		TCCR0 |= (1<<0); // no prescaler
		while (OVF_count < OVF)
		{
			while((TIFR0 & (1<<0)) == 0);//busy wait till TIFR=1
			TIFR0 |= (1<<0);//reset overflow
			OVF_count++;
		}
		TCCR0 = 0x00;//reset timer
		return TIMER_OK;
		}
		return TIMER_ERROR;
	}

