/*
 * LED.c
 *
 * Created: 1/14/2023 9:11:06 PM
 *  Author: Mohamed_Gamal
 */ 

#include "led.h"



En_LEDerror_t LED_init(uint8_t ledPort,uint8_t ledPin){
	En_LEDerror_t LED_initError = LED_OK; 
	LED_initError=DIO_init(ledPin,ledPort,OUT);
	return LED_initError;
}
En_LEDerror_t LED_on(uint8_t ledPort,uint8_t ledPin){
	En_LEDerror_t LED_onError = LED_OK; 
	LED_onError=DIO_write(ledPin,ledPort,HIGH);
	return LED_onError;
}
En_LEDerror_t LED_off(uint8_t ledPort,uint8_t ledPin){
	En_LEDerror_t LED_offError = LED_OK;
	LED_offError=DIO_write(ledPin,ledPort,LOW);
	return LED_offError;
}
En_LEDerror_t LED_toggle(uint8_t ledPort,uint8_t ledPin){
	En_LEDerror_t LED_toggleError = LED_OK;
	LED_toggleError=DIO_toggle(ledPin,ledPort);
	return LED_toggleError;

}

En_TIMERerror_t LED_normal_delay (uint16_t ms) 
{
   En_TIMERerror_t TIMER_error_state = TIMER_ok;
   TIMER_error_state=TIMER0_delay(ms);
   return TIMER_error_state;
}

En_TIMERerror_t LED_PED_delay(uint8_t T_initial,uint8_t Prescaler,uint8_t novf,uint8_t block_flag)
{
	En_TIMERerror_t TIMER_error_state = TIMER_ok;

	return TIMER_error_state;
}


En_TIMERerror_t LED_blink_CAR(uint16_t ms,uint8_t LED_PORT,uint8_t LED_PIN)
{
		En_TIMERerror_t timer_blink_error = TIMER_ok;
		for(uint8_t i = 0 ;i<10 ; i++)
		{ // we need 10 blinks for 5 secs interval with 500ms in each blink	
		    timer_blink_error=TIMER0_delay(ms);
			LED_toggle(LED_PORT,LED_PIN);
			if(timer_blink_error)
			break;
		
		}
		return timer_blink_error;
	return timer_blink_error;
}

En_TIMERerror_t LED_blink_both(uint16_t ms,uint8_t LED_PORT_CAR,uint8_t LED_PIN_CAR,uint8_t LED_PORT_PED,uint8_t LED_PIN_PED)
{
	En_TIMERerror_t timer_blink_error = TIMER_ok;
	for(uint8_t i = 0 ;i<10 ; i++)
	{ // we need 10 blinks for 5 secs interval with 500ms in each blink
		timer_blink_error=TIMER0_delay(ms);
		LED_toggle(LED_PORT_CAR,LED_PIN_CAR);
		LED_toggle(LED_PORT_PED,LED_PIN_PED);
		if(timer_blink_error)
		break;
		
	}
	return timer_blink_error;
}