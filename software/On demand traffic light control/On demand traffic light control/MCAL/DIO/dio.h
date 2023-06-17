/*
 * dio.h
 *
 * Created: 1/14/2023 3:27:28 PM
 *  Author: Mohamed_Gamal
 */ 


#ifndef DIO_H_
#define DIO_H_

# include "../../Utilities/registers.h"
# include "../../Utilities/types.h"
# include "../../Utilities/bitManipulation_macros.h"

// ports
#define PORT_A 0
#define PORT_B 1
#define PORT_C 2
#define PORT_D 3

// directions
#define IN 0
#define OUT 1

//  values 
#define LOW 0
#define HIGH 1

// Enum for error handing

typedef enum En_DIOerror_t {
	DIO_OK,DIO_PROBLEM
}En_DIOerror_t;

// functions prototypes
En_DIOerror_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction);
En_DIOerror_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t  value);
En_DIOerror_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber);
En_DIOerror_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t*  value);



#endif /* DIO_H_ */