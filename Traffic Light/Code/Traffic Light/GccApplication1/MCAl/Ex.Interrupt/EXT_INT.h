/*
 * EXT_INT.h
 *
 * Created: 14/10/2022 07:05:39 م
 *  Author: Eldeeb
 */ 


#ifndef EXT_INT_H_
#define EXT_INT_H_

#define EX_INT0	     	__VECTOR_1
#define TIMER0_OVF			__VECTOR_11

# define sei()  __asm__ __volatile__ ("sei" ::: "memory")
# define cli()  __asm__ __volatile__ ("cli" ::: "memory")

#  define ISR(vector, ...)            \
void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
void vector (void)
#endif /* EXT_INT_H_ */