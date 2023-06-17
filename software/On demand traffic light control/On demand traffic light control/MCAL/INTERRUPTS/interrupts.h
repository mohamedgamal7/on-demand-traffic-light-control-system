/*
 * interrupts.h
 *
 * Created: 1/15/2023 7:20:21 PM
 *  Author: Mohamed_Gamal
 */ 



#ifndef INTERRUPTS_H_
#define INTERRUPTS_H_

# include "../../Utilities/registers.h"
# include "../../Utilities/bitManipulation_macros.h"



typedef enum En_INTERRUPTerror_t {
	INTERRUPT_OK,INTERRUPT_PROBLEM
}En_INTERRUPTerror_t;

//Interrupt vectors
#define EXT_INT_0 __vector_1
#define EXT_INT_1 __vector_2

//Enable interrupts
#define sei()  __asm__ __volatile__ ("sei" ::: "memory")
#define cli()  __asm__ __volatile__ ("cli" ::: "memory")

//functions prototypes
En_INTERRUPTerror_t falling_edge_setup(void);
En_INTERRUPTerror_t setup_int0(void);
//ISR macro
#define ISR(INT_VECT) \
void INT_VECT(void) __attribute__ ((signal,used)); \
void INT_VECT(void)

#endif /* INTERRUPTS_H_ */

