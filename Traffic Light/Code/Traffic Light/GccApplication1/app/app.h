/*
 * app.h
 *
 * Created: 14/10/2022 06:19:40 ص
 *  Author: Eldeeb
 */ 


#ifndef APP_H_
#define APP_H_
//#include "../MCAl/Ex.Interrupt/EXT_INT.h"
#include <avr/interrupt.h>
#include "../ECUAL/LED DRIVER/Led.h"
#include "../ECUAL/BUTTON DRIVER/Button.h"
#include "../MCAl/TIMER DRIVER/Timer.h"





//PORT Macros
#define CAR_Port          PORT_A
#define PED_Port          PORT_B
#define BUT_Port          PORT_D

// Car PIN Macros
#define Car_Green_PIN        Pin0
#define Car_Yellow_PIN       Pin1
#define Car_Red_PIN          Pin2

//PED PIN Macros
#define PED_Green_PIN        Pin0
#define PED_Yellow_PIN       Pin1
#define PED_Red_PIN          Pin2

//BUTTON PIN
#define PED_Button_PIN           Pin2

//Car Signal Condition Macros
#define Green_Cond       0
#define Yellow_Cond_1    1
#define Red_Cond         2
#define Yellow_Cond_2    3

//Timer0 Macros
#define N_OverFlow0      4


void app_init(void);
/*
Function_Name     : app_init
Function_Parameter: not Exist
return            : non return void
Function_for      : Initialization for app
*/

void app_star(void);
/*
Function_Name     : app_main
Function_Parameter: not Exist
return            : non return void
Function_for      : Implementation for app
*/

#endif /* APP_H_ */