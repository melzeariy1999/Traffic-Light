/*
 * Math.h
 *
 * Created: 14/10/2022 03:05:59 ص
 *  Author: Eldeeb
 */ 


#ifndef MATH_H_
#define MATH_H_

#define SET_BIT( PortNumber, PinNumber)        PortNumber |= (1<<PinNumber)
#define Clear_BIT( PortNumber, PinNumber)     ((PortNumber) &= ~(1<<PinNumber))
#define Toggle_BIT( PortNumber, PinNumber)     ((PortNumber) ^= (1<<(PinNumber)))
#define Get_BIT( PortNumber, PinNumber)       (((PortNumber) >> (PinNumber)) & 0x01)




#endif /* MATH_H_ */