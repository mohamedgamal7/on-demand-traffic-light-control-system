/*
 * Timer.c
 *
 * Created: 1/14/2023 9:17:10 PM
 *  Author: Mohamed_Gamal
 */ 
#include "Timer.h"
#include "../INTERRUPTS/interrupts.h"

uint8_t OVF; // global variable to count number of overflows
En_blocking_t isBlocked = unblocked ;  // global variable to know if interrupt occured while timer is counting
// 1. Timer initialization in normal mode of operation
En_TIMERerror_t TIMER0_init()
{
	En_TIMERerror_t TIMER0_init_error = TIMER_ok;
	TCCR0 = 0x00; // normal mode
	return TIMER0_init_error;
}

//2. Set Timer initial value 
En_TIMERerror_t TIMER0_set_initial_value(uint8_t init_val)
{
	En_TIMERerror_t TIMER0_initval_error = TIMER_ok;
	TCNT0 =  init_val ; // set it based on calculations
	return TIMER0_initval_error;
}

//3.start timing by setting bits for the prescaler
En_TIMERerror_t TIMER0_start(uint8_t prescaler)
{
En_TIMERerror_t TIMER0_start__error = TIMER_ok;
if(prescaler<no_prescaler||prescaler>clk_1024)   // prescaling values that are present in AVRatmega32 only are considered
TIMER0_start__error =TIMER_PROBLEM;
switch (prescaler)
{

	case no_prescaler :
	SET_BIT(TCCR0,CS00); 
	CLEAR_BIT(TCCR0,CS01); 
	CLEAR_BIT(TCCR0,CS02); 
	break;
	case clk_8 :
	SET_BIT(TCCR0,CS00); 
	CLEAR_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	break;
	case clk_64 :
	SET_BIT(TCCR0,CS00);
	SET_BIT(TCCR0,CS01);
	CLEAR_BIT(TCCR0,CS02);
	break;
	case clk_256 :
	CLEAR_BIT(TCCR0,CS00);
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	break;
	case clk_1024 :
	SET_BIT(TCCR0,CS00); 
	CLEAR_BIT(TCCR0,CS01);
	SET_BIT(TCCR0,CS02);
	break;
}

return TIMER0_start__error;
}

//4. Enable timer0 overflow interrupt
En_TIMERerror_t TIMER0_enable_ovf_interrupt()
{
	En_TIMERerror_t TIMER0_enable_ovf_interrupt_error = TIMER_ok;
	SET_BIT(TIMSK,TOIE0); //enable overflow interrupt
	return TIMER0_enable_ovf_interrupt_error;
}

//5.disable timer0 overflow interrupt
En_TIMERerror_t TIMER0_disable_ovf_interrupt()
{
	En_TIMERerror_t TIMER0_disable_ovf_interrupt_error = TIMER_ok;
	CLEAR_BIT(TIMSK,TOIE0); //disable overflow interrupt
	return TIMER0_disable_ovf_interrupt_error;
}

//6.stop timing by clearing the TCCRO register
En_TIMERerror_t TIMER0_stop()
{
	En_TIMERerror_t TIMER0_stop_error = TIMER_ok;
	TCCR0 = 0X00;
	return TIMER0_stop_error;

}

// delay function given the required timing
En_TIMERerror_t TIMER0_delay(uint16_t ms)
{
	En_TIMERerror_t TIMER0_delay_error = TIMER_ok;
	// 1.initialize the timer
	TIMER0_delay_error = TIMER0_init();
	if(!TIMER0_delay_error)
	{
		if (ms == delay_5sec)
		{  OVF = NOVFS_5secs ; 
          //2.set timer initial value for 5 sec delay	
		  TIMER0_set_initial_value(Tint_5sec);
		}
		else if (ms == delay_Halfsec)
		{  OVF = NOVFS_Halfsec;
		  //2.set timer initial value for half sec delay	
		  TIMER0_set_initial_value(Tint_Halfsec);
		}
		else
		{
			return TIMER_PROBLEM;
		}
		//3.start timing by setting bits for the prescaler
		TIMER0_delay_error = TIMER0_start(clk_1024);
		//4.enable global interrupts
		sei();
		if(!TIMER0_delay_error)
		// 5.enable TIMER0 overflow interrupts
		TIMER0_delay_error = TIMER0_enable_ovf_interrupt();
		else
		return TIMER_PROBLEM;
		while(OVF) //6.busy wait while overflow did not happen and checks if interrupt happens
		{
		  if(isBlocked==blocked)
		  break;
		}
		//7. disable overflow interrupt
		TIMER0_delay_error = TIMER0_disable_ovf_interrupt();
		if(!TIMER0_delay_error)
		TIMER0_delay_error = TIMER0_stop();
		else
		return TIMER0_delay_error;
	}
	else
	{
		return TIMER0_delay_error;
	}
	
	return TIMER0_delay_error;
}



ISR(TIMER0_OVF_vect) {
	// Decrement the number of overflows remaining
	if(OVF)
	OVF--;

}


