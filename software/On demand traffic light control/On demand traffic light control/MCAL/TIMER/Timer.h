/*
 * Timer.h
 *
 * Created: 1/14/2023 9:17:22 PM
 *  Author: Mohamed_Gamal
 */ 


#include "../../Utilities/registers.h"
# include "../../Utilities/bitManipulation_macros.h"
#include "../INTERRUPTS/interrupts.h"



// Prescalers available in AVR Atmega32 definitions
#define no_prescaler 1
#define clk_8 2
#define clk_64 3
#define clk_256 4
#define clk_1024 5

// prescaler control bits 
#define CS00 0
#define CS01 1
#define CS02 2

//overflow vector of timer0
#define TIMER0_OVF_vect __vector_11
// Timer interrupt enable control bit
#define TOIE0 0

// NUMBER OF OVERFLOWS FOR 5 SECS DELAY at 1024 prescaler
#define NOVFS_5secs 20
// NUMBER OF OVERFLOWS FOR .5 SECS DELAY at 1024 prescaler
#define NOVFS_Halfsec 2

// delays needed
#define delay_5sec 5000
#define delay_Halfsec 500

// initial value at TCNTO
#define Tint_5sec 0
#define Tint_Halfsec 6

// Enum for error handing
typedef enum En_blocking_t
{ unblocked,blocked
}En_blocking_t;

// Enum for error handing
typedef enum En_TIMERerror_t {
	TIMER_ok,TIMER_PROBLEM
}En_TIMERerror_t;

En_TIMERerror_t TIMER0_init();// TIMER0 initialization
En_TIMERerror_t TIMER0_set_initial_value(uint8_t init_val); // Set initial value of TCNTO based on your calculations
En_TIMERerror_t TIMER0_start(uint8_t prescaler); // start timer
En_TIMERerror_t TIMER0_enable_ovf_interrupt(); //enable overflow interrupt
En_TIMERerror_t TIMER0_disable_ovf_interrupt(); //disable overflow interrupt
En_TIMERerror_t TIMER0_stop(); //stop timer
En_TIMERerror_t TIMER0_delay(uint16_t ms);// Timer delay with a specified value

