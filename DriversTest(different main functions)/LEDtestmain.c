# include "ECUAL/LED/LED.h"
int main(void)
{

	En_LEDerror_t PIN3state;
	En_LEDerror_t PIN2state;
	En_LEDerror_t PIN1state;


	PIN3state=LED_init(3,PORT_A);
	PIN2state=LED_init(2,PORT_A);
	PIN1state=LED_init(1,PORT_A);


    while(1)
    {
		// Testing the driver
		
		// Test a LED as on
		if (!PIN3state)
		LED_on(3,PORT_A);
		// Test a LED as off
		if (!PIN2state)
		LED_off(2,PORT_A);
		// Toggle LED
		if (!PIN1state)
		LED_toggle(1,PORT_A);
	
		

    }
}