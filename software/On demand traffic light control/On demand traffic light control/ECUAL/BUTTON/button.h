/*
 * button.h
 *
 * Created: 1/14/2023 7:28:30 PM
 *  Author: Mohamed_Gamal
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_
# include "../../MCAL/DIO/dio.h"

typedef enum En_Buttonerror_t {
	BUTTON_OK,BUTTON_PROBLEM
}En_Buttonerror_t;

En_Buttonerror_t BUTTON_init(uint8_t buttonPin,uint8_t buttonPort);
En_Buttonerror_t BUTTON_read(uint8_t buttonPin,uint8_t buttonPort,uint8_t *value);


#endif /* BUTTON_H_ */