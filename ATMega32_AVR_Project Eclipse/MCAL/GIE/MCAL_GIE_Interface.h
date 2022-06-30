/*
 * MCAL_GIE_Interface.h
 *
 *  Created on: Jun 20, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_MGIE_MCAL_GIE_INTERFACE_H_
#define MCAL_MGIE_MCAL_GIE_INTERFACE_H_

/***************_APP_INCLUDES_*****************************/
#include "../../APP/Utility/APP_Utility.h"

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_GIE_Private.h"
#include "MCAL_GIE_Config.h"
#include "MCAL_GIE_Register.h"

/*============================================================================
  ==================_APIs Supported by "MCAL_GIE DRIVER"_=====================
  ============================================================================*/

/*GIE Enable Function*/
void MGIE_vGlobalInterruptEnable(void);
/*GIE Disable Function*/
void MGIE_vGlobalInterruptDisable(void);

#endif /* MCAL_MGIE_MCAL_GIE_INTERFACE_H_ */
