/*
 * MCAL_EXTI_Interface.h
 *
 *  Created on: Jun 21, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_EXTI_MCAL_EXTI_INTERFACE_H_
#define MCAL_EXTI_MCAL_EXTI_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "../../APP/Utility/APP_Utility.h"

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_EXTI_Private.h"
#include "MCAL_EXTI_Config.h"
#include "MCAL_EXTI_Register.h"

/***************_Macros_Configuration_*********************/


/*============================================================================
 ==================_APIs Supported by "MCAL_EXTI DRIVER"_====================
 ============================================================================*/
void MEXTI0_vInitiate (void);
void MEXTI1_vInitiate (void);
void MEXTI2_vInitiate (void);

void MEXTI0_vDisable(void);
void MEXTI1_vDisable(void);
void MEXTI2_vDisable(void);

void MEXTI0_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void));
void MEXTI1_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void));
void MEXTI2_vSetCallBack_Execution(void (*LPtr_toFUNCTION)(void));

#endif /* MCAL_EXTI_MCAL_EXTI_INTERFACE_H_ */
