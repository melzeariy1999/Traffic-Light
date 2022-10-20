/*
 * DIO.c
 *
 * Created: 14/10/2022 02:31:41 ص
 *  Author: 
 */ 
#include "DIO.h"

void DIO_init(uint8_t PinNumber, uint8_t PortNumber, uint8_t direction)
{
	//check that PortNumber and PinNumber in the range
	if ((PortNumber <= PORT_D) && (PinNumber <= Pin7))
	{
		if (direction == IN)
		{
			switch (PortNumber)
			{
				case PORT_A: Clear_BIT(DDRA, PinNumber); break;
				case PORT_B: Clear_BIT(DDRB, PinNumber); break;
				case PORT_C: Clear_BIT(DDRC, PinNumber); break;
				case PORT_D: Clear_BIT(DDRC, PinNumber); break;
			}
		}
		else if (direction == OUT)
		{
			switch (PortNumber)
			{
				case PORT_A: SET_BIT(DDRA, PinNumber); break;
				case PORT_B: SET_BIT(DDRB, PinNumber); break;
				case PORT_C: SET_BIT(DDRC, PinNumber); break;
				case PORT_D: SET_BIT(DDRD, PinNumber); break;
			}
		}
	}
	else
	{
		//Error State
	}
}

void DIO_write(uint8_t PinNumber, uint8_t PortNumber, uint8_t value)
{
	//check that PortNumber and PinNumber in the range
	if ((PortNumber <= PORT_D) && (PinNumber <= Pin7))
	{
		if (value == LOW)
		{
			switch (PortNumber)
			{
				case PORT_A: Clear_BIT(PORTA, PinNumber); break;
				case PORT_B: Clear_BIT(PORTB, PinNumber); break;
				case PORT_C: Clear_BIT(PORTC, PinNumber); break;
				case PORT_D: Clear_BIT(PORTD, PinNumber); break;
			}
		}
		else if (value == HIGH)
		{
			switch (PortNumber)
			{
				case PORT_A: SET_BIT(PORTA, PinNumber); break;
				case PORT_B: SET_BIT(PORTB, PinNumber); break;
				case PORT_C: SET_BIT(PORTC, PinNumber); break;
				case PORT_D: SET_BIT(PORTD, PinNumber); break;
			}
		}
	}
	else
	{
		//Error State
	}
}

void DIO_read(uint8_t PinNumber, uint8_t PortNumber, uint8_t* value)
{
	//check that PortNumber and PinNumber in the range
	if ((PortNumber <= PORT_D) && (PinNumber <= Pin7))
	{
		switch (PortNumber)
		{
			case PORT_A: *value = Get_BIT(PINA, PinNumber); break;
			case PORT_B: *value = Get_BIT(PINB, PinNumber); break;
			case PORT_C: *value = Get_BIT(PINC, PinNumber); break;
			case PORT_D: *value =  (PIND & (1<<PinNumber) )>>PinNumber ; break;
		}

	}
	else
	{
		//Error State
	}
}

void DIO_toggle(uint8_t PinNumber, uint8_t PortNumber)
{
	//check that PortNumber and PinNumber in the range
	if ((PortNumber <= PORT_D) && (PinNumber <= Pin7))
	{

		switch (PortNumber)
		{
			case PORT_A:  Toggle_BIT(PORTA, PinNumber); break;
			case PORT_B:  Toggle_BIT(PORTB, PinNumber); break;
			case PORT_C:  Toggle_BIT(PORTC, PinNumber); break;
			case PORT_D:  Toggle_BIT(PORTD, PinNumber); break;
		}
	}
	else
	{
		//Error State
	}
}