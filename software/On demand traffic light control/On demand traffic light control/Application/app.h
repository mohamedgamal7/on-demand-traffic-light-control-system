/*
 * app.h
 *
 * Created: 1/14/2023 9:14:29 PM
 *  Author: Mohamed_Gamal
 */ 


#ifndef APP_H_
#define APP_H_

/* --------------------------------------------------INCLUDING DIRVERS & UTILITIES---------------------------------------- */

#include "../ECUAL/LED/led.h"
#include "../ECUAL/BUTTON/button.h"

#include "../Utilities/bitManipulation_macros.h"
#include "../Utilities/registers.h"
#include "../Utilities/types.h"

/* ----------------------------------------------------------------------------------------------------------- */

void APP_init(void);
void APP_start(void);

extern En_blocking_t isBlocked;

//LED PORTS DEFINITIONS
#define LED_CAR_PORT PORT_A
#define LED_PED_PORT PORT_B

//LED PINS DEFINITIONS
#define LED_CAR_G_PIN 0
#define LED_CAR_Y_PIN 1
#define LED_CAR_R_PIN 2

#define LED_PED_G_PIN 0
#define LED_PED_Y_PIN 1
#define LED_PED_R_PIN 2

// BUTTON PORT DEFINITIONS
#define INT_BUTTON_PORT PORT_D

// BUTTON PIN DEFINITIONS
#define INT_BUTTON_PIN 2


// MODES OF OPERATION
typedef enum En_MODE_t 
{ normal,pedestrian 
}En_MODE_t;



typedef enum En_first_click_t
{ unclicked,first
}En_first_click_t;


typedef enum En_CAR_LED_ON_t
{ green_c,yellow_c,red_c
}En_CAR_LED_ON_t;



#endif /* APP_H_ */