/*
 * MCAL_GIE.c
 *
 *  Created on: Jun 20, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#include"MCAL_GIE_Interface.h"

/*GIE Enable Function*/
void MGIE_vGlobalInterruptEnable(void) {
	SET_BIT(REG_SREG, 7);
}
/*GIE Disable Function*/
void MGIE_vGlobalInterruptDisable(void) {
	CLR_BIT(REG_SREG, 7);
}

