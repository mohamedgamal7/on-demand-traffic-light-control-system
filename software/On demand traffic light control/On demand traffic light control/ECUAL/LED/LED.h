/*
 * LED.h
 *
 * Created: 1/14/2023 7:27:47 PM
 *  Author: Mohamed_Gamal
 */ 


#ifndef LED_H_
#define LED_H_

#define LOW 0 
#define HIGH 1

# include "../../MCAL/DIO/dio.h"
# include "../../MCAL/TIMER/Timer.h"
# include "../../Utilities/registers.h"
typedef enum En_LEDerror_t {
	LED_OK,LED_PROBLEM
}En_LEDerror_t;

En_LEDerror_t LED_init(uint8_t ledPort,uint8_t ledPin);
En_LEDerror_t LED_on(uint8_t ledPort,uint8_t ledPin);
En_LEDerror_t LED_off(uint8_t ledPort,uint8_t ledPin);
En_LEDerror_t LED_toggle(uint8_t ledPort,uint8_t ledPin);
En_TIMERerror_t LED_normal_delay (uint16_t ms) ;
En_TIMERerror_t LED_blink_CAR(uint16_t ms,uint8_t LED_PORT,uint8_t LED_PIN);
En_TIMERerror_t LED_blink_both(uint16_t ms,uint8_t LED_PORT_CAR,uint8_t LED_PIN_CAR,uint8_t LED_PORT_PED,uint8_t LED_PIN_PED);
En_TIMERerror_t LED_PED_delay(uint8_t T_initial,uint8_t Prescaler,uint8_t novf,uint8_t block_flag);


#endif /* LED_H_ */