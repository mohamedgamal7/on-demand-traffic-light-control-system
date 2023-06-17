/*
 * bitManipulation_macros.h
 *
 * Created: 1/14/2023 6:16:56 PM
 *  Author: Mohamed_Gamal
 */ 


#ifndef BITMANIPULATION_MACROS_H_
#define BITMANIPULATION_MACROS_H_


#define SET_BIT(REG,BIT) (REG|=(1<<BIT))
#define CLEAR_BIT(REG,BIT) (REG&=(~(1<<BIT)))
#define TOGGLE_BIT(REG,BIT) (REG^=(1<<BIT))
#define READ_BIT(REG,BIT) ( (REG & (1<<BIT))>>BIT )


#endif /* BITMANIPULATION_MACROS_H_ */