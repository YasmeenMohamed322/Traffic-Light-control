


#ifndef EXTI_PRIVATE_H_
#define EXTI_PRIVATE_H_
#define INT0 0
#define MCUCR (*(volatile uint8_t*)(0x55))
#define ISC00 0
#define ISC01 1

#define MCUCSR (*(volatile uint8_t*)(0x54))
#define MCUCSR_INT0 6
#define GICR (*(volatile uint8_t*)(0x5B))
#define GICR_INT0 6
#define GIFR (*(volatile uint8_t*)(0x5A))
#define GIFR_INT0 6

#define FALLING_EDGE 0
#define RISING_EDGE 1
#define LOW_LEVEL 2
#define Change 3

#define Enable 1
#define Disable 0
#define INT0_VECT __vector_1

#define NULL 0
#endif /* EXTI_PRIVATE_H_ */