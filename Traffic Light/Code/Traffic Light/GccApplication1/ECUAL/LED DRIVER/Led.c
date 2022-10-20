/*
 * Led.c
 *
 * Created: 14/10/2022 03:39:41 ص
 *  Author: Eldeeb
 */ 

#include "Led.h"

void LED_Init(uint8_t LedPort, uint8_t LedPin)
{
	DIO_init(LedPin, LedPort, OUT);           
}
void LED_on(uint8_t LedPort, uint8_t LedPin)
{
	DIO_write(LedPin, LedPort, HIGH);           
}
void LED_off(uint8_t LedPort, uint8_t LedPin)
{
	DIO_write(LedPin, LedPort, LOW);
}
void LED_toggle(uint8_t LedPort, uint8_t LedPin)
{
	DIO_toggle(LedPin, LedPort);
}