/*
 * main.c
 *
 * Created: 1/14/2023 12:31:15 PM
 *  Author: Mohamed_Gamal
 */ 

# include "ECUAL/LED/LED.h"
#include "ECUAL/TIMER/Timer.h"
# include "Utilities/interrupts.h"

# include "Utilities/interrupts.h"
#include "ECUAL/LED/LED.h"
#include "ECUAL/BUTTON/button.h"

uint8_t lednumber = 0 ;

int main(void)
{
	//1.initialize LEDS
	LED_init(2,PORT_A);
	LED_init(3,PORT_A);
	LED_init(7,PORT_A);
	
	//initialize button;
	BUTTON_init(2,PORT_D);
	
	//2.Enable global interrupts
	sei();
	
	//3. choosing interrupt sense
	RISING_EDGE_SETUP();
	
	//4. enabling external INTO
	SETUP_INT0();
	
	
	while(1)
	{
		switch(lednumber)
		{
			case 0 :
	
			LED_off(3,PORT_A);
			LED_off(7,PORT_A);
			break;
			case 1 :

			
			LED_on(3,PORT_A);
			LED_on(7,PORT_A);
			break;
			default:
			break;

		}
	}
    

	
}

	ISR(EXT_INT_0)
	{
		if(lednumber<1)
		{
			lednumber++;
		}
		else
		{
			lednumber=0;
		}
	}