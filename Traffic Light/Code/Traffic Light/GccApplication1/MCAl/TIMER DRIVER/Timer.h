/*
 * Timer.h
 *
 * Created: 14/10/2022 04:56:56 ص
 *  Author: Eldeeb
 */ 


#ifndef TIMER_H_
#define TIMER_H_
#include "../../register.h"


/*==========================================================(Timer Macros)=====================================================================//
************************************************************************************************************************************************/
//Timer Mode Macros
#define Normal_Mode    0
#define PWM_Phase_Mode 1
#define CTC_Mode       2
#define Fast_PWM_Mode  3

//Prescaller Mode Macros
#define No_Prescaller     0
#define Prescaller_8      1
#define Prescaller_64     2
#define Prescaller_265    3
#define Prescaller_1024   4

//TIMSK 0 Register Macros
#define TOIE0     0
#define OCIE0     1


//TCCR 0 Register Macros
#define CS00     0
#define CS01     1
#define CS02     2
#define WGM01    3
#define WGM00    6

//TIFR 0 Register Macros#define TOV0   0

//MCUR
#define ISC00 0
#define ISC01 1

//GICR
#define INT0 6


/*==========================================================(Timer0Function Prototypes)===============================================//
************************************************************************************************************************************************/

void Timer0_Set(uint8_t Timer_Mode);
/*
Function_Name     : Timer0_Set
Function_Parameter: Timer_Mode
return            : non return void
Function_for      : Set the Mode of Timer0
*/
void Timer0_Start(uint8_t Prescaller, uint8_t init_Value);
/*
Function_Name     : Timer0_Start
Function_Parameter: Prescaller , init_Value
return            : non return void
Function_for      : Set Prescaller and init_Value
*/
void Timer0_Delay(uint8_t Prescaller, uint8_t init_Value, uint32_t n_of_OverFlow);
/*
Function_Name     : Timer0_Delay
Function_Parameter: Prescaller , init_Value , n_of_OverFlow
return            : non return void
Function_for      : call Timer0_Start Function and Timer0_Stop Function and set n.OverFlow
*/




#endif