/*
 * register.h
 *
 * Created: 14/10/2022 02:28:02 ص
 *  Author: Eldeeb
 */ 


#ifndef REGISTER_H_
#define REGISTER_H_

#include "Math.h"
#include "types.h"

//PORTA Register
#define PORTA *((volatile uint8_t*)0x3B) //8-bit-register
#define DDRA *((volatile uint8_t*)0x3A)   //8-bit-register
#define PINA *((volatile uint8_t*)0x39)   //8-bit-register

//PORTB Register
#define PORTB *((volatile uint8_t*)0x38) //8-bit-register
#define DDRB *((volatile uint8_t*)0x37)  //8-bit-register
#define PINB *((volatile uint8_t*)0x36)  //8-bit-register

//PORTC Register
#define PORTC *((volatile uint8_t*)0x35) //8-bit-register
#define DDRC *((volatile uint8_t*)0x34)  //8-bit-register
#define PINC *((volatile uint8_t*)0x33)  //8-bit-register

//PORTD Register
#define PORTD *((volatile uint8_t*)0x32) //8-bit-register
#define DDRD *((volatile uint8_t*)0x31)  //8-bit-register
#define PIND *((volatile uint8_t*)0x30)  //8-bit-register

//Timer 0 Register
#define  TCCR0 *((volatile uint8_t*)0x53) //8-bit-register
#define  TIFR  *((volatile uint8_t*)0x58) //8-bit-register
#define TCNT0  *((volatile uint8_t*)0x52) //8-bit-register
//Interrupt Register
#define   MCUCSR   (*((volatile uint8_t*)0x54)) //8-bit-register
#define   SREG     (*((volatile uint8_t*)0x5F)) //8-bit-register
#define   MCUCR    (*((volatile uint8_t*)0x55)) //8-bit-register
#define   GIFR     (*((volatile uint8_t*)0x5A)) //8-bit-register
#define   GICR     (*((volatile uint8_t*)0x5B)) //8-bit-register
#define   TIMSK    (*((volatile uint8_t*)0x59)) //8-bit-register
#endif /* REGISTER_H_ */
