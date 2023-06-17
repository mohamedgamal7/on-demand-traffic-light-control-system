/*
 * dio.c
 *
 * Created: 1/14/2023 3:27:39 PM
 *  Author: Mohamed_Gamal
 */ 

#include "dio.h"

// Initializes input direction for a specific pin in a port
En_DIOerror_t DIO_init(uint8_t pinNumber, uint8_t portNumber, uint8_t direction)
{
	En_DIOerror_t DIO_initError = DIO_OK;
	if ((pinNumber<0||pinNumber > 7) ||(portNumber<0 || portNumber> 3)) // wrong pinNumber or portNumber
	{
		DIO_initError = DIO_PROBLEM;
		return DIO_initError;

	}

	switch(portNumber){
		case PORT_A:
		if(direction == IN)
		{
			CLEAR_BIT(DDRA,pinNumber);
		}

		else if (direction == OUT)
		{
			SET_BIT(DDRA,pinNumber);
		}
		else
		{
			DIO_initError = DIO_PROBLEM;
			return DIO_initError;
		}
		break;

		case PORT_B:
		if(direction == IN)
		{
			CLEAR_BIT(DDRB,pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRB,pinNumber);
		}
		else
		{
			DIO_initError = DIO_PROBLEM;
			return DIO_initError;
		}
		break;

		case PORT_C:
		if(direction == IN)
		{
			CLEAR_BIT(DDRC,pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRC,pinNumber);
		}
		else
		{
			DIO_initError = DIO_PROBLEM;
			return DIO_initError;
		}
		break;
		case PORT_D:
		if(direction == IN)
		{
			CLEAR_BIT(DDRD,pinNumber);
		}
		else if (direction == OUT)
		{
			SET_BIT(DDRD,pinNumber);
		}
		else
		{
			DIO_initError = DIO_PROBLEM;
			return DIO_initError;
		}
		break;
	}
        return DIO_initError;
}

// Clear or set a specific bit in a port
En_DIOerror_t DIO_write(uint8_t pinNumber, uint8_t portNumber, uint8_t  value)
{
		
		En_DIOerror_t DIO_writeError = DIO_OK;
		if ((pinNumber<0||pinNumber > 7) ||(portNumber<0 || portNumber> 3)) // wrong pinNumber or portNumber
		{
			DIO_writeError = DIO_PROBLEM;
			return DIO_writeError;

		}
		switch(portNumber){
			case PORT_A:
			if(value == LOW)
			{
				CLEAR_BIT(PORTA,pinNumber);
			}
			
			else if (value == HIGH)
			{
				SET_BIT(PORTA,pinNumber);
			}
	        else
	        {
		        return DIO_PROBLEM; // handles wrong direction
	        }
			break;
			
			case PORT_B:
			if(value == LOW)
			{
				CLEAR_BIT(PORTB,pinNumber);
			}
			else if (value == HIGH)
			{
				SET_BIT(PORTB,pinNumber);
			}
		    else
		    {
				DIO_writeError = DIO_PROBLEM;
				return DIO_writeError;
		    }
			break;
			
			case PORT_C:
			if(value == LOW)
			{
				CLEAR_BIT(PORTC,pinNumber);
			}
			else if (value == HIGH)
			{
				SET_BIT(PORTC,pinNumber);
			}
			else
			{
				DIO_writeError = DIO_PROBLEM;
				return DIO_writeError;
			}
			break;
			
			case PORT_D:
			if(value == LOW)
			{
				CLEAR_BIT(PORTD,pinNumber);
			}
			else if (value == HIGH)
			{
				SET_BIT(PORTD,pinNumber);
			}
			else
			{
				DIO_writeError = DIO_PROBLEM;
				return DIO_writeError;
			}
			break;
			
		}
		return DIO_writeError;
}

// Toggle a specific bit in a port 
En_DIOerror_t DIO_toggle(uint8_t pinNumber, uint8_t portNumber)
{  
	En_DIOerror_t DIO_toggleError = DIO_OK;
	if ((pinNumber<0||pinNumber > 7) ||(portNumber<0 || portNumber> 3)) // wrong pinNumber or portNumber
	{
		DIO_toggleError = DIO_PROBLEM;
		return DIO_toggleError;
	}
		
	switch(portNumber){
		case PORT_A:
		TOGGLE_BIT(PORTA,pinNumber);
		break;
		case PORT_B:
		TOGGLE_BIT(PORTB,pinNumber);
		break;
		case PORT_C:
		TOGGLE_BIT(PORTC,pinNumber);
		break;
		case PORT_D:
		TOGGLE_BIT(PORTD,pinNumber);
		break;
	}
	return DIO_toggleError;
}

// Read the value of a specific bit in a port 
En_DIOerror_t DIO_read(uint8_t pinNumber, uint8_t portNumber, uint8_t*  value)
{ 
		En_DIOerror_t DIO_readError = DIO_OK;
		if ((pinNumber<0||pinNumber > 7) ||(portNumber<0 || portNumber> 3)) // wrong pinNumber or portNumber
		{
			DIO_readError = DIO_PROBLEM;
			return DIO_readError;
		}
		switch(portNumber){
		case PORT_A:
			*value = READ_BIT(PINA,pinNumber);
		break;
		case PORT_B:
			*value = READ_BIT(PINB,pinNumber);
		break;
		case PORT_C:
			*value = READ_BIT(PINC,pinNumber);
		break;
		case PORT_D:
			*value = READ_BIT(PIND,pinNumber);
		break;
	}
	return DIO_readError;
}