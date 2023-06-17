
# include "MCAL/DIO/dio.h"
int main(void)
{
	En_DIOerror_t PIN5state;
	En_DIOerror_t PIN4state;
	En_DIOerror_t PIN3state;
	En_DIOerror_t PIN2state;
	En_DIOerror_t PIN1state;

	PIN4state=DIO_init(4,PORT_A,OUT);
    PIN5state=DIO_init(5,PORT_A,OUT);
	PIN3state=DIO_init(3,PORT_A,OUT);
	PIN2state=DIO_init(2,PORT_A,OUT);
	PIN1state=DIO_init(1,PORT_A,IN);


    while(1)
    {
		// Testing the driver
		
		// Test a pin as an output high
		if (!PIN4state)
		DIO_write(4,PORT_A,HIGH);
		// Test a pin as an output low
		if (!PIN3state)
		DIO_write(3,PORT_A,LOW);
		// Toggle a pin
		if (!PIN2state)
		DIO_toggle(2,PORT_A);
		// check if a pin is high make another pin high 
		uint8_t* pin4portAval = 0;
		DIO_read(4,PORT_A,pin4portAval);
		if(*pin4portAval)
		{
			if(!PIN5state)
			DIO_write(5,PORT_A,HIGH);
		}
		
		// Test a pin as an input from VCC
		// input a vcc to it 
		

    }
}