/*
 * MCAL_EXTI_Register.h
 *
 *  Created on: Jun 24, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_EXTI_MCAL_EXTI_REGISTER_H_
#define MCAL_EXTI_MCAL_EXTI_REGISTER_H_

#define EXTI_PERIPH_REG_GICR_BASE_ADDRESS       0x5B
#define EXTI_PERIPH_REG_GIFR_BASE_ADDRESS       0x5A
#define EXTI_PERIPH_REG_MCUCR_BASE_ADDRESS      0x55
#define EXTI_PERIPH_REG_MCUCSR_BASE_ADDRESS     0x54

#define REG_GICR      (*((volatile u8*)EXTI_PERIPH_REG_GICR_BASE_ADDRESS))
#define REG_GIFR      (*((volatile u8*)EXTI_PERIPH_REG_GIFR_BASE_ADDRESS))
#define REG_MCUCR     (*((volatile u8*)EXTI_PERIPH_REG_MCUCR_BASE_ADDRESS))
#define REG_MCUCSR    (*((volatile u8*)EXTI_PERIPH_REG_MCUCSR_BASE_ADDRESS))



/*      _____  ______ _____       __  __  _____ _    _  _____ _____
 *     |  __ \|  ____/ ____|     |  \/  |/ ____| |  | |/ ____|  __ \
 *     | |__) | |__ | |  __      | \  / | |    | |  | | |    | |__) |
 *     |  _  /|  __|| | |_ |     | |\/| | |    | |  | | |    |  _  /
 *     | | \ \| |___| |__| |  _  | |  | | |____| |__| | |____| | \ \
 *     |_|  \_\______\_____| (_) |_|  |_|\_____|\____/ \_____|_|  \_\
 *     MCUCR REGISTER DEFINITION - [MCU Control Register]
 *     REGISTER MISSION:	[1] Interrupt sense control for EXTI0 and EXTI1
 -----------------------------------------------------------------------------
 ||_7_||  ||_6_||  ||_5_||  ||_4_||  ||_3_||  ||_2_||  ||_1_||  ||_0_||
 R        R        R        R        ISC11    ISC10    ISC01    ISC00
 -----------------------------------------------------------------------------*/
#define MCUCR_ISC00	0U
#define MCUCR_ISC01	1U
#define MCUCR_ISC10	2U
#define MCUCR_ISC11	3U

/*      _____  ______ _____       __  __  _____ _    _  _____  _____ _____
 *     |  __ \|  ____/ ____|     |  \/  |/ ____| |  | |/ ____|/ ____|  __ \
 *     | |__) | |__ | |  __      | \  / | |    | |  | | |    | (___ | |__) |
 *     |  _  /|  __|| | |_ |     | |\/| | |    | |  | | |     \___ \|  _  /
 *     | | \ \| |___| |__| |  _  | |  | | |____| |__| | |____ ____) | | \ \
 *     |_|  \_\______\_____| (_) |_|  |_|\_____|\____/ \_____|_____/|_|  \_\
 *     MCUCSR REGISTER DEFINITION - [MCU Control and Status Register]
 *     REGISTER MISSION:	[1] Interrupt sense control for EXTI2
 -----------------------------------------------------------------------------
 ||_7_||  ||_6_||  ||_5_||  ||_4_||  ||_3_||  ||_2_||  ||_1_||  ||_0_||
 R        ISC2     R        R        R        R        R        R
 -----------------------------------------------------------------------------*/
#define MCUCSR_ISC2	6U


/*      _____  ______ _____        _____ _____ _____ _____
 *     |  __ \|  ____/ ____|      / ____|_   _/ ____|  __ \
 *     | |__) | |__ | |  __      | |  __  | || |    | |__) |
 *     |  _  /|  __|| | |_ |     | | |_ | | || |    |  _  /
 *     | | \ \| |___| |__| |  _  | |__| |_| || |____| | \ \
 *     |_|  \_\______\_____| (_)  \_____|_____\_____|_|  \_\
 *     GICR REGISTER DEFINITION - [General Interrupt Control Register]
 *     REGISTER MISSION:	[1] Enable/Disable Interrupts EXTI0, EXTI1, EXTI2
 -----------------------------------------------------------------------------
 ||_7_||  ||_6_||  ||_5_||  ||_4_||  ||_3_||  ||_2_||  ||_1_||  ||_0_||
 INT1     INT0     INT2     R        R        R        R        R
 -----------------------------------------------------------------------------*/
#define GICR_INT1 7U
#define GICR_INT0 6U
#define GICR_INT2 5U

/*      _____  ______ _____        _____ _____ ______ _____
 *     |  __ \|  ____/ ____|      / ____|_   _|  ____|  __ \
 *     | |__) | |__ | |  __      | |  __  | | | |__  | |__) |
 *     |  _  /|  __|| | |_ |     | | |_ | | | |  __| |  _  /
 *     | | \ \| |___| |__| |  _  | |__| |_| |_| |    | | \ \
 *     |_|  \_\______\_____| (_)  \_____|_____|_|    |_|  \_\
 *     GIFR REGISTER DEFINITION - [General Interrupt Flag Register]
 *     REGISTER MISSION:	[1] Identifying interrupts Requests EXTI0, EXTI1, EXTI2
 -----------------------------------------------------------------------------
 ||_7_||  ||_6_||  ||_5_||  ||_4_||  ||_3_||  ||_2_||  ||_1_||  ||_0_||
 INTF1    INTF0    INTF2    R        R        R        R        R
 -----------------------------------------------------------------------------*/
#define GIFR_INTF1 6U
#define GIFR_INTF0 7U
#define GIFR_INTF2 5U

#endif /* MCAL_EXTI_MCAL_EXTI_REGISTER_H_ */
