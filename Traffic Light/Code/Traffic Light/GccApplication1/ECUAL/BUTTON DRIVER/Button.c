/*
 * Button.c
 *
 * Created: 14/10/2022 03:55:53 ص
 *  Author: Eldeeb
 */ 

#include "Button.h"
void BUTTON_Init(uint8_t ButtonPin, uint8_t ButtonPort)
{
	DIO_init(ButtonPin, ButtonPort, IN);
}
void BUTTON_read(uint8_t ButtonPin, uint8_t ButtonPort, uint8_t *value)
{
	DIO_read(ButtonPin, ButtonPort, value);
}