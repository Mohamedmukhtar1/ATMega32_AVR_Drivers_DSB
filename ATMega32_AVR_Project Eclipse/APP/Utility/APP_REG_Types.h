/*
 * APP_REG_Types.h
 *
 *  Created on: May 13, 2022
 *      Author: Eng- Mohamed Mokhtar
 */

#ifndef INC_APP_UTILITY_APP_REG_TYPES_H_
#define INC_APP_UTILITY_APP_REG_TYPES_H_

/* 8_bit Register Typedef ***************************************************************/
typedef union {
	struct {
		u8 BIT0 :1;
		u8 BIT1 :1;
		u8 BIT2 :1;
		u8 BIT3 :1;
		u8 BIT4 :1;
		u8 BIT5 :1;
		u8 BIT6 :1;
		u8 BIT7 :1;
	} BitAccess;
	u8 RegAccess;
} Reg_8Bit_ut;

/* 16_bit Register Typedef **************************************************************/
typedef union {
	struct Bit_Order {
		u16 BIT0 :1;
		u16 BIT1 :1;
		u16 BIT2 :1;
		u16 BIT3 :1;
		u16 BIT4 :1;
		u16 BIT5 :1;
		u16 BIT6 :1;
		u16 BIT7 :1;
		u16 BIT8 :1;
		u16 BIT9 :1;
		u16 BIT10 :1;
		u16 BIT11 :1;
		u16 BIT12 :1;
		u16 BIT13 :1;
		u16 BIT14 :1;
		u16 BIT15 :1;
	} BitAccess;
	struct {
		u16 BYTE0 :8;
		u16 BYTE1 :8;
	} ByteAccess;
	u16 RegAccess;
} Reg_16Bit_ut;

#endif /* INC_APP_UTILITY_APP_REG_TYPES_H_ */
