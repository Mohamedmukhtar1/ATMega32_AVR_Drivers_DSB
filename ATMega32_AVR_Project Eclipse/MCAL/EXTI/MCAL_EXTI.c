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
	SIGN_BIT(REG_MCUCR.BitAccess.ISC00_Bit, LOW_BIT);
	SIGN_BIT(REG_MCUCR.BitAccess.ISC01_Bit, HGH_BIT);
	#elif	EXTINT_0_SENSE_CTRL_MODE ==	RISING_EDGE
	SIGN_BIT(REG_MCUCR.BitAccess.ISC00_Bit, HGH_BIT);
	SIGN_BIT(REG_MCUCR.BitAccess.ISC01_Bit, HGH_BIT);
	#elif	EXTINT_0_SENSE_CTRL_MODE ==	LOW_LEVEL
	SIGN_BIT(REG_MCUCR.BitAccess.ISC00_Bit, LOW_BIT);
	SIGN_BIT(REG_MCUCR.BitAccess.ISC01_Bit, LOW_BIT);
	#elif	EXTINT_0_SENSE_CTRL_MODE ==	ANY_LOGICAL_CHANGE
	SIGN_BIT(REG_MCUCR.BitAccess.ISC00_Bit, HGH_BIT);
	SIGN_BIT(REG_MCUCR.BitAccess.ISC01_Bit, LOW_BIT);
	#endif
	// ENABLE GLOBAL INTERRUPT
	SIGN_BIT(REG_GICR.BitAccess.INT0_Bit, HGH_BIT); // ENABLE EXTERNAL INTERRUPT 0
}

void MEXTI0_vDisable(void)
{
	SIGN_BIT(REG_GICR.BitAccess.INT0_Bit, LOW_BIT); // TO DISABLE EXTERNAL INTERRUPT 0
}

u8 MEXTI0_u8GetInterruptFlag(void)
{
	return REG_GIFR.BitAccess.INTF0_Bit ;
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
	SIGN_BIT(REG_MCUCR.BitAccess.ISC10_Bit, LOW_BIT);
	SIGN_BIT(REG_MCUCR.BitAccess.ISC11_Bit, HGH_BIT);
	#elif	EXTINT_1_SENSE_CTRL_MODE ==	RISING_EDGE
	SIGN_BIT(REG_MCUCR.BitAccess.ISC10_Bit, HGH_BIT);
	SIGN_BIT(REG_MCUCR.BitAccess.ISC11_Bit, HGH_BIT);
	#elif	EXTINT_1_SENSE_CTRL_MODE ==	LOW_LEVEL
	SIGN_BIT(REG_MCUCR.BitAccess.ISC10_Bit, LOW_BIT);
	SIGN_BIT(REG_MCUCR.BitAccess.ISC11_Bit, LOW_BIT);
	#elif	EXTINT_1_SENSE_CTRL_MODE ==	ANY_LOGICAL_CHANGE
	SIGN_BIT(REG_MCUCR.BitAccess.ISC10_Bit, HGH_BIT);
	SIGN_BIT(REG_MCUCR.BitAccess.ISC11_Bit, LOW_BIT);
	#endif
	// ENABLE GLOBAL INTERRUPT
	SIGN_BIT(REG_GICR.BitAccess.INT1_Bit, HGH_BIT); // TO ENABLE EXTERNAL INTERRUPT 1
}

void MEXTI1_vDisable(void)
{
	SIGN_BIT(REG_GICR.BitAccess.INT1_Bit, LOW_BIT); // TO DISABLE EXTERNAL INTERRUPT 1
}

u8 MEXTI1_u8GetInterruptFlag(void)
{
	return REG_GIFR.BitAccess.INTF1_Bit ;
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
	SIGN_BIT(REG_MCUCSR.BitAccess.ISC2_Bit, LOW_BIT);
	#elif	EXTINT_2_SENSE_CTRL_MODE ==	RISING_EDGE
	SIGN_BIT(REG_MCUCSR.BitAccess.ISC2_Bit, HGH_BIT);
	#endif
	// ENABLE GLOBAL INTERRUPT
	SIGN_BIT(REG_GICR.BitAccess.INT2_Bit, HGH_BIT); // TO ENABLE EXTERNAL INTERRUPT 2
}

void MEXTI2_vDisable(void)
{
	SIGN_BIT(REG_GICR.BitAccess.INT2_Bit, LOW_BIT); // TO DISABLE EXTERNAL INTERRUPT 2
}

u8 MEXTI2_u8GetInterruptFlag(void)
{
	return REG_GIFR.BitAccess.INTF2_Bit ;
}

void MEXTI2_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void))
{
	GPtr_EXTI2_CallBack_Fun = LPtr_toFUNCTION;
}

void ISR_EXTI_2_Vector(void)
{
	GPtr_EXTI2_CallBack_Fun();
}

