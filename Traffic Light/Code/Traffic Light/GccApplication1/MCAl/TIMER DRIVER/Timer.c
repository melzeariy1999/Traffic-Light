/*
 * Timer.c
 *
 * Created: 14/10/2022 04:56:34 ص
 *  Author: Eldeeb
 */ 

#include "Timer.h"

void Timer0_Set(uint8_t Timer_Mode)
{
		switch (Timer_Mode)
		{
			case Normal_Mode:
			Clear_BIT(TCCR0, WGM00);
			Clear_BIT(TCCR0, WGM01);
			break;
			case PWM_Phase_Mode:
			SET_BIT(TCCR0, WGM00);
			Clear_BIT(TCCR0, WGM01);
			break;
			case CTC_Mode:
			Clear_BIT(TCCR0, WGM00);
			SET_BIT(TCCR0, WGM01);
			break;
			case Fast_PWM_Mode:
			SET_BIT(TCCR0, WGM00);
			SET_BIT(TCCR0, WGM01);
			break;
			default:
			//Error Handling
			break;
    	}
}
		

void Timer0_Start(uint8_t Prescaller, uint8_t init_Value)
{
		TCNT0 = init_Value;
		switch (Prescaller)
		{
			case No_Prescaller:
			SET_BIT(TCCR0, CS00);
			Clear_BIT(TCCR0, CS01);
			Clear_BIT(TCCR0, CS02);
			break;
			case Prescaller_8:
			Clear_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			Clear_BIT(TCCR0, CS02);
			break;
			case Prescaller_64:
			SET_BIT(TCCR0, CS00);
			SET_BIT(TCCR0, CS01);
			Clear_BIT(TCCR0, CS02);
			break;
			case Prescaller_265:
			Clear_BIT(TCCR0, CS00);
			Clear_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
			case Prescaller_1024:
			SET_BIT(TCCR0, CS00);
			Clear_BIT(TCCR0, CS01);
			SET_BIT(TCCR0, CS02);
			break;
			default:
			//Error Handling
			break;
		}
}

void Timer0_Delay(uint8_t Prescaller, uint8_t init_Value, uint32_t n_of_OverFlow)
{
    uint32_t Count_OverFlow = 0;
    Timer0_Start(Prescaller, init_Value);  //Calling Timer0_Start

    while (Count_OverFlow < n_of_OverFlow) //wait until Count_OverFlow Reach to n_of_OverFlow
    {
       while ((TIFR &(1<<TOV0)) == 0); //wait until TIFR is set
       TIFR |= (1<<TOV0);             //Clear Flag
        Count_OverFlow++;
    }
     Count_OverFlow = 0;
     TCCR0 = 0x00;                     //Timer0_Stop

}


