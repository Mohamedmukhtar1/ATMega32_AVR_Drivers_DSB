/*
 * MCAL_ATmega32_Register.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_H_
#define MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_H_

/***************_APP_INCLUDES_*****************************/
#include "../../APP/Utility/APP_Utility.h"

/***************_MCAL_INCLUDES_****************************/
#include "MCAL_ATmega32_Register_Private.h"
#include "MCAL_ATmega32_Register_Config.h"


/***************_Macros_Configuration_*********************/


/***************_EndOF_Macros_Configuration_***************/


/*******************************************************************************************
 *       ____ ____ ___ ___        ____           _       _                    _
 *      / ___|  _ \_ _/ _ \      |  _ \ ___ _ __(_)_ __ | |__   ___ _ __ __ _| |
 *     | |  _| |_) | | | | |     | |_) / _ \ '__| | '_ \| '_ \ / _ \ '__/ _` | |
 *     | |_| |  __/| | |_| |  _  |  __/  __/ |  | | |_) | | | |  __/ | | (_| | |
 *      \____|_|  |___\___/  (_) |_|   \___|_|  |_| .__/|_| |_|\___|_|  \__,_|_|
 *                                                |_|
 *******************************************************************************************/
#define REG_PORTA	(*((volatile PORT_ut *) PORTA_BaseAddress))
#define REG_PORTB	(*((volatile PORT_ut *) PORTB_BaseAddress))
#define REG_PORTC	(*((volatile PORT_ut *) PORTC_BaseAddress))
#define REG_PORTD	(*((volatile PORT_ut *) PORTD_BaseAddress))
/*************************************************/
#define REG_DDRA	(*((volatile DDR_ut *) DDRA_BaseAddress))
#define REG_DDRB	(*((volatile DDR_ut *) DDRB_BaseAddress))
#define REG_DDRC	(*((volatile DDR_ut *) DDRC_BaseAddress))
#define REG_DDRD	(*((volatile DDR_ut *) DDRD_BaseAddress))
/*************************************************/
#define REG_PINA	(*((volatile PIN_ut *) PINA_BaseAddress))
#define REG_PINB	(*((volatile PIN_ut *) PINB_BaseAddress))
#define REG_PINC	(*((volatile PIN_ut *) PINC_BaseAddress))
#define REG_PIND	(*((volatile PIN_ut *) PIND_BaseAddress))


/*******************************************************************************************
 *         _    ____   ____       ____           _       _                    _
 *        / \  |  _ \ / ___|     |  _ \ ___ _ __(_)_ __ | |__   ___ _ __ __ _| |
 *       / _ \ | | | | |         | |_) / _ \ '__| | '_ \| '_ \ / _ \ '__/ _` | |
 *      / ___ \| |_| | |___   _  |  __/  __/ |  | | |_) | | | |  __/ | | (_| | |
 *     /_/   \_\____/ \____| (_) |_|   \___|_|  |_| .__/|_| |_|\___|_|  \__,_|_|
 *                                                |_|
 *******************************************************************************************/
#define REG_ADMUX    (*((volatile ADMUX_ut *)ADMUX_BaseAddress ))
#define REG_ADCSRA   (*((volatile ADCSRA_ut*)ADCSRA_BaseAddress))
#define REG_ADCH     (*((volatile SFIOR_ut *)ADCH_BaseAddress  ))
#define REG_ADCL     (*((volatile SFIOR_ut *)ADCL_BaseAddress  ))
#define REG_ADCD	 (*((volatile ADCD_ut  *)ADCD_BaseAddress  ))

/*******************************************************************************************
 *      _______  _______ ___       ____           _       _                    _
 *     | ____\ \/ /_   _|_ _|     |  _ \ ___ _ __(_)_ __ | |__   ___ _ __ __ _| |
 *     |  _|  \  /  | |  | |      | |_) / _ \ '__| | '_ \| '_ \ / _ \ '__/ _` | |
 *     | |___ /  \  | |  | |   _  |  __/  __/ |  | | |_) | | | |  __/ | | (_| | |
 *     |_____/_/\_\ |_| |___| (_) |_|   \___|_|  |_| .__/|_| |_|\___|_|  \__,_|_|
 *                                                 |_|
 *******************************************************************************************/
#define REG_MCUCR    (*((volatile MCUCR_ut *)MCUCR_BaseAddress ))
#define REG_MCUCSR	 (*((volatile MCUCSR_ut*)MCUCSR_BaseAddress))
#define REG_GICR	 (*((volatile GICR_ut  *)GICR_BaseAddress  ))
#define REG_GIFR     (*((volatile GIFR_ut  *)GIFR_BaseAddress  ))



#define REG_SFIOR	(*((volatile SFIOR_ut*)SFIOR_BaseAddress))


#endif /* MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_H_ */

