/*
 * Button.h
 *
 * Created: 14/10/2022 03:56:16 ص
 *  Author: Eldeeb
 */ 


#ifndef BUTTON_H_
#define BUTTON_H_

#include "../../MCAL/DIO DRIVER/DIO.h"

//****************************************************************(Button Macros)**************************************************************//
//*********************************************************************************************************************************************//
//Button State Macros
#define LOW  0
#define HIGH 1


//*******************************************************( Button Function Prototypes)**********************************************************//
//**********************************************************************************************************************************************//

void BUTTON_Init(uint8_t ButtonPin, uint8_t ButtonPort);
/*
Function_Name     : BUTTON_Init
Function_Parameter: ButtonPin, ButtonPort
return            : non return void
Function_for      : Making Pins to be Input "0"
*/
void BUTTON_read(uint8_t ButtonPin, uint8_t ButtonPort , uint8_t *value);
/*
Function_Name     : BUTTON_read
Function_Parameter: ButtonPin, ButtonPort , *value
return            : non return void
Function_for      : Read ButtonPin State
*/


#endif /* BUTTON_H_ */