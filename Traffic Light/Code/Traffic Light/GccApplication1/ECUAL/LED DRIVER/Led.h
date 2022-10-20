/*
 * Led.h
 *
 * Created: 14/10/2022 03:39:29 ص
 *  Author: Eldeeb
 */ 


#ifndef LED_H_
#define LED_H_

#include "../../MCAL/DIO DRIVER/DIO.h"

//*******************************************************( LED Function Prototypes)**********************************************************//
//**********************************************************************************************************************************************//

void LED_Init(uint8_t LedPort, uint8_t LedPin);
/*
Function_Name     : LED_Init
Function_Parameter: LedPort, LedPin
return            : non return void
Function_for      : Making Pins to be Input "0"
*/
void LED_on(uint8_t LedPort, uint8_t LedPin);
/*
Function_Name     : LED_on
Function_Parameter: LedPort, LedPin
return            : non return void
Function_for      : write on Pin High
*/
void LED_off(uint8_t LedPort, uint8_t LedPin);
/*
Function_Name     : LED_off
Function_Parameter: LedPort, LedPin
return            : non return void
Function_for      : write on Pin Low
*/
void LED_toggle(uint8_t LedPort, uint8_t LedPin);
/*
Function_Name     : LED_off
Function_Parameter: LedPort, LedPin
return            : non return void
Function_for      : write on Pin Low
*/



#endif /* LED_H_ */