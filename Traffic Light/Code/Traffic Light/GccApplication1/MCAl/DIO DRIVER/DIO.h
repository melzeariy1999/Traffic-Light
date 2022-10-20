/*
 * DIO.h
 *
 * Created: 14/10/2022 02:31:27 ص
 *  Author: Eldeeb
 */ 


#ifndef DIO_H_
#define DIO_H_

#include "../../register.h"

//******************************************************************(DIO Macros)**************************************************************//
//*********************************************************************************************************************************************//

//Ports Macros
#define PORT_A   0
#define PORT_B   1
#define PORT_C   2
#define PORT_D   3

//Pins Macros
#define Pin0   0
#define Pin1   1
#define Pin2   2
#define Pin4   4
#define Pin5   5
#define Pin6   6
#define Pin7   7

//Pin Direction Macros
#define IN  0
#define OUT 1

//Pin Value Macros
#define LOW  0
#define HIGH 1


//**********************************************************( DIO Function Prototypes)**********************************************************//
//**********************************************************************************************************************************************//

void DIO_init(uint8_t PinNumber, uint8_t PortNumber, uint8_t direction);
/*
Function_Name     : DIO_init
Function_Parameter: PinNumber, PortNumber, direction
return            : non return void
Function_for      : Making Pins to be Input "0" or Output "1"
*/

void DIO_write(uint8_t PinNumber, uint8_t PortNumber, uint8_t value);
/*
Function_Name     : DIO_write
Function_Parameter: PinNumber, PortNumber, direction
return            : non return void
Function_for      : Writing on Pins Low "0" or High "1"
*/

void DIO_toggle(uint8_t PinNumber, uint8_t PortNumber);
/*
Function_Name     : DIO_toggle
Function_Parameter: PinNumber, PortNumber
return            : non return void
Function_for      : Toggle DIO Pins
*/

void DIO_read(uint8_t PinNumber, uint8_t PortNumber, uint8_t *value);
/*
Function_Name     : DIO_read
Function_Parameter: PinNumber, PortNumber , *value
return            : non return void
Function_for      : Read from DIO Pins
*/




#endif /* DIO_H_ */