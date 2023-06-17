/*
 * interrupts.c
 *
 * Created: 1/19/2023 5:12:17 PM
 *  Author: Mohamed_Gamal
 */ 
# include "interrupts.h"
//Falling edge setup 
En_INTERRUPTerror_t falling_edge_setup(void)
{
	En_INTERRUPTerror_t FALLING_EDGE_SETUP_ERROR = INTERRUPT_OK;
    MCUCR|= (1<<1);// ISO1 equals 1 and ISOO equals 0 
 return FALLING_EDGE_SETUP_ERROR;
}

// Setup into as the desired interrupt
En_INTERRUPTerror_t setup_int0(void)
{
	En_INTERRUPTerror_t setup_int0_ERROR = INTERRUPT_OK;
	
	GICR|=(1<<6); //Enables INTO
	return setup_int0_ERROR;
}

