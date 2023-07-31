#include "SysTick.h"

void Systick_Delay_1ms(void)
{
	NVIC_ST_CTRL_R = 0 ;   // TO DISABLE SYSTICK TIMER DURING CONFIGURATION
	NVIC_ST_RELOAD_R = 80000 - 1;                    
	NVIC_ST_CURRENT_R = 0;
	NVIC_ST_CTRL_R = 0x05;    // TO ENABLE SYSTICK TIMER WITH MC CLOCK RATE
	while(GET_BIT(NVIC_ST_CTRL_R,16)==0);
	
}

void Systick_Delay_ms(unsigned long time)
{
	unsigned long i ;
	for( i = 0 ; i<time/5 ; i++)
	{
		Systick_Delay_1ms();  // DELAY 1ms
	}
	
}
