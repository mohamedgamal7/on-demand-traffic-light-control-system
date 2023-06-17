/*
 * main.c
 *
 * Created: 1/14/2023 12:31:15 PM
 *  Author: Mohamed_Gamal
 */ 

# include "ECUAL/LED/LED.h"
#include "ECUAL/TIMER/Timer.h"
# include "Utilities/interrupts.h"

int main(void)
{
	//  led toggle each 5000 ms (5 seconds)

// 1. Initialize LEDS
En_LEDerror_t LED_error_state = LED_init(2,PORT_A);
if(LED_error_state==LED_OK)
{
	// 2. Initialize Timer0
	En_TIMERerror_t TIMER_error_state = TIMER0_init();
	if(TIMER_error_state==TIMER_ok)
	{
		//3.set timer starting value according to calculations
		TIMER_error_state= TIMER0_set_initial_value(0);
		if (TIMER_error_state==TIMER_ok)
		{
		
			while(1)
			{
			 TIMER_error_state = TIMER0_start(clk_1024);
			 if(TIMER_error_state == TIMER_ok)
			 {
				uint8_t ovfcount=0,novf= 19 ;
				    while(ovfcount<novf)
				    {
					    TIMER0_counting();
						ovfcount++;
				    }
					ovfcount=0;
					TIMER0_stop();
			 }
			 	
					if(TIMER_error_state == TIMER_ok)
				LED_toggle(2,PORT_A);
			}
		}
	}
	
}