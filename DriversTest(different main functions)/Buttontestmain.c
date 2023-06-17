 include "ECUAL/BUTTON/button.h"
# include "ECUAL/LED/LED.h"

int main(void)
{

	En_Buttonerror_t PIN3state;
	PIN3state=BUTTON_init(3,PORT_A);
	En_LEDerror_t PIN2state;
	PIN2state=LED_init(2,PORT_A);


    while(1)
    {
		// Testing the driver
		
		// Test if a button is pressed a LED is turned on 
		if (!PIN3state)
		{
			uint8_t* ValBUTTON = 0 ;
			En_Buttonerror_t BUTTONerror = BUTTON_read(3,PORT_A,ValBUTTON);
			if(BUTTONerror==BUTTON_OK && *ValBUTTON==HIGH)
			{
				if(!PIN2state)
				PIN2state=LED_on(2,PORT_A);
			}
			else if (BUTTONerror==BUTTON_OK && *ValBUTTON==LOW)
			{
					if(!PIN2state)
					PIN2state=LED_off(2,PORT_A);
			}
			
		}
			
			
		}

	
		

    
}