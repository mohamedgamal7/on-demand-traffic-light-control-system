/*
 * button.c
 *
 * Created: 1/14/2023 7:28:43 PM
 *  Author: Mohamed_Gamal
 */ 

#include "button.h"

En_Buttonerror_t BUTTON_init(uint8_t buttonPort,uint8_t buttonPin)
{
	En_Buttonerror_t BUTTON_initerror = BUTTON_OK;
	BUTTON_initerror = DIO_init(buttonPort,buttonPin,IN); // always an input 
	return BUTTON_initerror;
}

En_Buttonerror_t BUTTON_read(uint8_t buttonPort,uint8_t buttonPin,uint8_t *value) // important to read the status of the button when pressed 
{
	En_Buttonerror_t BUTTON_readerror = BUTTON_OK;
	BUTTON_readerror = DIO_read(buttonPort,buttonPin,value);
	return BUTTON_readerror;
}