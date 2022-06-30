/*
 * MCAL_EXTI_Private.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_EXTI_MCAL_EXTI_PRIVATE_H_
#define MCAL_EXTI_MCAL_EXTI_PRIVATE_H_

/* EXTINT0, EXTINT1, EXTINT2, EXTERNAL INTERRUPT SENSE MODE OPTIONS:
[1] LOW_LEVEL,		[2] RISING_EDGE,
[3] FALLING_EDGE,	[4] ANY_LOGICAL_CHANGE*/
#define FALLING_EDGE		1U
#define RISING_EDGE			2U
#define LOW_LEVEL			3U
#define ANY_LOGICAL_CHANGE	4U


#define ISR_EXTI_0_Vector	__vector_1
void ISR_EXTI_0_Vector(void)__attribute__((signal));

#define ISR_EXTI_1_Vector	__vector_2
void ISR_EXTI_1_Vector(void)__attribute__((signal));

#define ISR_EXTI_2_Vector	__vector_3
void ISR_EXTI_2_Vector(void)__attribute__((signal));

#endif /* MCAL_EXTI_MCAL_EXTI_PRIVATE_H_ */
