/*
 * MCAL_ATmega32_Register_Private.h
 *
 *  Created on: Jun 30, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_PRIVATE_H_
#define MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_PRIVATE_H_

typedef union {
	struct {
		u8 PORTx0 :1;
		u8 PORTx1 :1;
		u8 PORTx2 :1;
		u8 PORTx3 :1;
		u8 PORTx4 :1;
		u8 PORTx5 :1;
		u8 PORTx6 :1;
		u8 PORTx7 :1;
	} BitAccess;
	u8 RegAccess;
} PORT_ut;

typedef union {
	struct {
		u8 DDRx0 :1;
		u8 DDRx1 :1;
		u8 DDRx2 :1;
		u8 DDRx3 :1;
		u8 DDRx4 :1;
		u8 DDRx5 :1;
		u8 DDRx6 :1;
		u8 DDRx7 :1;
	} BitAccess;
	u8 RegAccess;
} DDR_ut;

typedef union {
	struct {
		u8 Pinx0 :1;
		u8 Pinx1 :1;
		u8 Pinx2 :1;
		u8 Pinx3 :1;
		u8 Pinx4 :1;
		u8 Pinx5 :1;
		u8 Pinx6 :1;
		u8 Pinx7 :1;
	} BitAccess;
	u8 RegAccess;
} PIN_ut;

typedef union {
	struct {
		u8 MUX_Bits  :5; // Analog Channel and Gain Selection from MUX0 .. MUX4
		u8 ADLAR_Bit :1; // ADC Left Adjust Result
		u8 REFS0_Bit :1; // Reference Selection 0
		u8 REFS1_Bit :1; // Reference Selection 1
	} BitAccess;
	u8 RegAccess;
} ADMUX_ut;

typedef union {
	struct {
		u8 ADPS0_Bit :1; // ADC Prescaler Select 0
		u8 ADPS1_Bit :1; // ADC Prescaler Select 1
		u8 ADPS2_Bit :1; // ADC Prescaler Select 2
		u8 ADIE_Bit  :1; // ADC Interrupt Enable
		u8 ADIF_Bit  :1; // ADC Interrupt Flag
		u8 ADATE_Bit :1; // ADC Auto Trigger Enable
		u8 ADSC_Bit  :1; // ADC Start Conversion
		u8 ADEN_Bit  :1; // ADC Enable
	} BitAccess;
	u8 RegAccess;
} ADCSRA_ut;

typedef union {
	u16 RegAccessRightAdjusted :10;
	Reg_16Bit_ut RegAccess;
} ADCD_ut;

typedef union {
	struct {
		u8 PSR10_Bit :1; // Prescaler Reset Timer/Counter1 and Timer/Counter0
		u8 PSR2_Bit  :1; // Prescaler Reset Timer/Counter2
		u8 PUD_Bit   :1; // Pull-up disable (neglecting DDxn, PORTxn to enable the pull-ups)
		u8 ACME_Bit  :1; // Analog Comparator Multiplexer Enable
		u8 _Rsrv_Bit :1;
		u8 ADTS0_Bit :1; // ADC Auto Trigger Source 0
		u8 ADTS1_Bit :1; // ADC Auto Trigger Source 1
		u8 ADTS2_Bit :1; // ADC Auto Trigger Source 2
	} BitAccess;
	u8 RegAccess;
} SFIOR_ut;

typedef union {
	struct {
		u8 ISC00_Bit :1; // Interrupt 0 Sense Control Bit 0
		u8 ISC01_Bit :1; // Interrupt 0 Sense Control Bit 1
		u8 ISC10_Bit :1; // Interrupt 1 Sense Control Bit 0
		u8 ISC11_Bit :1; // Interrupt 1 Sense Control Bit 1
		u8 SM0_Bit   :1; // Sleep Mode Select Bit 0
		u8 SM1_Bit   :1; // Sleep Mode Select Bit 1
		u8 SM2_Bit   :1; // Sleep Mode Select Bit 2
		u8 SE_Bit    :1; // Sleep Mode Enable
	} BitAccess;
	u8 RegAccess;
} MCUCR_ut;

typedef union {
	struct {
		u8 PORF_Bit  :1; // Power-on Reset Flag
		u8 EXTRF_Bit :1; // External Reset Flag
		u8 BORF_Bit  :1; // Brown-out Reset Flag
		u8 WDRF_Bit  :1; // Watchdog Reset Flag
		u8 JTRF_Bit  :1; // JTAG Reset Flag
		u8 _Rsrv_Bit :1;
		u8 ISC2_Bit  :1; // Interrupt 2 Sense Control Bit
		u8 JTD_Bit   :1; // JTAG Interface Disable
	} BitAccess;
	u8 RegAccess;
} MCUCSR_ut;

typedef union {
	struct {
		u8 IVCE_Bit  :1; // Interrupt Vector Select
		u8 IVSEL_Bit :1; // Interrupt Vector Change Enable
		u8 _Rsrv_Bit :3;
		u8 INT2_Bit  :1; // External Interrupt Request 2 Enable
		u8 INT0_Bit  :1; // External Interrupt Request 0 Enable
		u8 INT1_Bit  :1; // External Interrupt Request 1 Enable
	} BitAccess;
	u8 RegAccess;
} GICR_ut;

typedef union {
	struct {
		u8 _Rsrv_Bit :5;
		u8 INTF2_Bit :1; // External Interrupt Request 2 Enable
		u8 INTF0_Bit :1; // External Interrupt Request 0 Enable
		u8 INTF1_Bit :1; // External Interrupt Request 1 Enable
	} BitAccess;
	u8 RegAccess;
} GIFR_ut;

#endif /* MCAL_ATMEG32_REGISTERS_MCAL_ATMEGA32_REGISTER_PRIVATE_H_ */
