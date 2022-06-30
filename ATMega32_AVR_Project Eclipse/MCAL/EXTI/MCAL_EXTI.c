/*
 * MCAL_EXTI.c
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include "MCAL_EXTI_Interface.h"

void (*GPtr_EXTI0_CallBack_Fun)(void) = NULL;
void (*GPtr_EXTI1_CallBack_Fun)(void) = NULL;
void (*GPtr_EXTI2_CallBack_Fun)(void) = NULL;

void MEXTI0_vInitiate (void)
{
	#if		EXTINT_0_SENSE_CTRL_MODE ==	FALLING_EDGE
	CLR_BIT(REG_MCUCR, MCUCR_ISC00);
	SET_BIT(REG_MCUCR, MCUCR_ISC01);
	#elif	EXTINT_0_SENSE_CTRL_MODE ==	RISING_EDGE
	SET_BIT(REG_MCUCR, MCUCR_ISC00);
	SET_BIT(REG_MCUCR, MCUCR_ISC01);
	#elif	EXTINT_0_SENSE_CTRL_MODE ==	LOW_LEVEL
	CLR_BIT(REG_MCUCR, MCUCR_ISC00);
	CLR_BIT(REG_MCUCR, MCUCR_ISC01);
	#elif	EXTINT_0_SENSE_CTRL_MODE ==	ANY_LOGICAL_CHANGE
	SET_BIT(REG_MCUCR, MCUCR_ISC00);
	CLR_BIT(REG_MCUCR, MCUCR_ISC01);
	#endif
	// ENABLE GLOBAL INTERRUPT
	SET_BIT(REG_GICR, GICR_INT0); // TO ENABLE EXTERNAL INTERRUPT 0
}

void MEXTI0_vDisable(void)
{
	CLR_BIT(REG_GICR, GICR_INT0); // TO DISABLE EXTERNAL INTERRUPT 0
}

void MEXTI0_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void))
{
	GPtr_EXTI0_CallBack_Fun = LPtr_toFUNCTION;
}
void ISR_EXTI_0_Vector(void)
{
	GPtr_EXTI0_CallBack_Fun();
}


void MEXTI1_vInitiate (void)
{
	#if		EXTINT_1_SENSE_CTRL_MODE ==	FALLING_EDGE
	CLR_BIT(REG_MCUCR, MCUCR_ISC10);
	SET_BIT(REG_MCUCR, MCUCR_ISC11);
	#elif	EXTINT_1_SENSE_CTRL_MODE ==	RISING_EDGE
	SET_BIT(REG_MCUCR, MCUCR_ISC10);
	SET_BIT(REG_MCUCR, MCUCR_ISC11);
	#elif	EXTINT_1_SENSE_CTRL_MODE ==	LOW_LEVEL
	CLR_BIT(REG_MCUCR, MCUCR_ISC10);
	CLR_BIT(REG_MCUCR, MCUCR_ISC11);
	#elif	EXTINT_1_SENSE_CTRL_MODE ==	ANY_LOGICAL_CHANGE
	SET_BIT(REG_MCUCR, MCUCR_ISC10);
	CLR_BIT(REG_MCUCR, MCUCR_ISC11);
	#endif
	// ENABLE GLOBAL INTERRUPT
	SET_BIT(REG_GICR, GICR_INT1); // TO ENABLE EXTERNAL INTERRUPT 1
}

void MEXTI1_vDisable(void)
{
	CLR_BIT(REG_GICR, GICR_INT1); // TO DISABLE EXTERNAL INTERRUPT 1
}

void MEXTI1_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void))
{
	GPtr_EXTI1_CallBack_Fun = LPtr_toFUNCTION;
}

void ISR_EXTI_1_Vector(void)
{
	GPtr_EXTI1_CallBack_Fun();
}


void MEXTI2_vInitiate (void)
{
	#if		EXTINT_2_SENSE_CTRL_MODE ==	FALLING_EDGE
	CLR_BIT(REG_MCUCR, MCUCSR_ISC2);
	#elif	EXTINT_2_SENSE_CTRL_MODE ==	RISING_EDGE
	SET_BIT(REG_MCUCR, MCUCSR_ISC2);
	#endif
	// ENABLE GLOBAL INTERRUPT
	// TO ENABLE EXTERNAL INTERRUPT 2
	SET_BIT(REG_GICR, GICR_INT2);
}

void MEXTI2_vDisable(void)
{
	CLR_BIT(REG_GICR, GICR_INT2); // TO DISABLE EXTERNAL INTERRUPT 2
}

void MEXTI2_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void))
{
	GPtr_EXTI2_CallBack_Fun = LPtr_toFUNCTION;
}

void ISR_EXTI_2_Vector(void)
{
	GPtr_EXTI2_CallBack_Fun();
}
