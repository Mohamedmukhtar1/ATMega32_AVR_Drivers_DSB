/*
 * HAL_LCD.c
 *
 * Created: 2022-04-10 02:43:37 PM
 *  Author: Eng- Mohamed Mokhtar
 */

#include "HAL_LCD_Interface.h"
u8 Char1[8] = { 0X00, 0X0A, 0X1F, 0X1F, 0X1F, 0X0E, 0X04, 0X00 };
// Folded Heart = 0x0, 0xa, 0x1f, 0x1f, 0x1f, 0xe, 0x4, 0x0
// Right Arrow  = 0x0, 0x4, 0x2, 0x1f, 0x2, 0x4, 0x0, 0x0
// Left Arrow   = 0x0, 0x4, 0x8, 0x1f, 0x8, 0x4, 0x0, 0x0
u8 Char2[8] = { 0x04, 0x1F, 0x11, 0x11, 0x1F, 0x1F, 0x1F, 0x1F };
u8 Char3[8] = { 0x04, 0x0E, 0x0E, 0x0E, 0x1F, 0x00, 0x04, 0x00 };
u8 Char4[8] = { 0x01, 0x03, 0x07, 0x1F, 0x1F, 0x07, 0x03, 0x01 };
u8 Char5[8] = { 0x01, 0x03, 0x05, 0x09, 0x09, 0x0B, 0x1B, 0x18 };
u8 Char6[8] = { 0x0A, 0x0A, 0x1F, 0x11, 0x11, 0x0E, 0x04, 0x04 };
u8 Char7[8] = { 0x00, 0x00, 0x0A, 0x00, 0x04, 0x11, 0x0E, 0x00 };
u8 Char8[8] = { 0x00, 0x0A, 0x1F, 0x1F, 0x0E, 0x04, 0x00, 0x00 };

void HLCD_vInitiate(void) {
	MGPIO_InitPinMode(LCD_RS_PORT, LCD_RS_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_EN_PORT, LCD_EN_PIN, GPIO_OUTPUT);
	//MCAL_DIO_PIN_MODE(LCD_RW_PIN,OUTPUT_STATE); // the manufacturer is grounding the pin

#if LCD_MODE     ==   _8_BIT_MODE
	MGPIO_InitPinMode(LCD_8BIT_DATA_PORT, LCD_DATA_0_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_8BIT_DATA_PORT, LCD_DATA_1_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_8BIT_DATA_PORT, LCD_DATA_2_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_8BIT_DATA_PORT, LCD_DATA_3_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_8BIT_DATA_PORT, LCD_DATA_4_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_8BIT_DATA_PORT, LCD_DATA_5_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_8BIT_DATA_PORT, LCD_DATA_6_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_8BIT_DATA_PORT, LCD_DATA_7_PIN, GPIO_OUTPUT);
	Delay_vMilliSecond16MHzoscillator(10);
	HLCD_vWriteCommand(LCD_COMMAND_ACTIVATE_8_BITMODE);

#elif LCD_MODE    ==   _4_BIT_MODE
	MGPIO_InitPinMode(LCD_4BIT_DATA_PORT, LCD_DATA_4_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_4BIT_DATA_PORT, LCD_DATA_5_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_4BIT_DATA_PORT, LCD_DATA_6_PIN, GPIO_OUTPUT);
	MGPIO_InitPinMode(LCD_4BIT_DATA_PORT, LCD_DATA_7_PIN, GPIO_OUTPUT);
	Delay_vMilliSecond16MHzoscillator(10);
	HLCD_vWriteCommand(LCD_COMMAND_1_ACTIVATE_4_BITMODE);
	Delay_vMilliSecond16MHzoscillator(2);
	HLCD_vWriteCommand(LCD_COMMAND_2_ACTIVATE_4_BITMODE);
	Delay_vMilliSecond16MHzoscillator(2);
	HLCD_vWriteCommand(LCD_COMMAND_3_ACTIVATE_4_BITMODE);
#endif
	Delay_vMilliSecond16MHzoscillator(2);
	HLCD_vWriteCommand(LCD_COMMAND_DISPLAY_ON_CURSOR_OFF);
	Delay_vMilliSecond16MHzoscillator(2);
	HLCD_vWriteCommand(LCD_COMMAND_CLEAR_SCREEN);
	Delay_vMilliSecond16MHzoscillator(2);
	HLCD_vWriteCommand(LCD_COMMAND_RETURN_HOME_CLEAR_SCREEN);
	Delay_vMilliSecond16MHzoscillator(2);
	HLCD_vWriteCommand(LCD_COMMAND_CURSOR_INCREMENT);
}

void HLCD_vWriteCommand(u8 Lu8_LCD_Command) {
	MGPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_LOW); // Fetal operation if High while "Command Transfer"
	//MGPIO_WritePin(LCD_RW_PIN, GPIO_LOW); // Held Low for "Write Operation"
	/**********************	_8_BIT_MODE	*************************/
#if LCD_MODE    ==   _8_BIT_MODE
	//MGPIO_WritePin(LCD_8BIT_DATA_PORT, LCD_DATA_0_PIN, GET_BIT(Lu8_LCD_Command, 0));
	MGPIO_WritePort(LCD_8BIT_DATA_PORT, Lu8_LCD_Command);
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_HIGH);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_LOW);
	Delay_vMilliSecond16MHzoscillator(2);

	/**********************	_4_BIT_MODE	*************************/
#elif LCD_MODE    ==   _4_BIT_MODE
	/***   Sending HIGH Nibble of 8 Bits Data   ***/
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_4_PIN,
			GET_BIT(Lu8_LCD_Command, 4U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_5_PIN,
			GET_BIT(Lu8_LCD_Command, 5U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_6_PIN,
			GET_BIT(Lu8_LCD_Command, 6U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_7_PIN,
			GET_BIT(Lu8_LCD_Command, 7U));
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_HIGH);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_LOW);
	Delay_vMilliSecond16MHzoscillator(2);
	/***   Sending LOW Nibble of 8 Bits Data    ***/
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_4_PIN,
			GET_BIT(Lu8_LCD_Command, 0U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_5_PIN,
			GET_BIT(Lu8_LCD_Command, 1U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_6_PIN,
			GET_BIT(Lu8_LCD_Command, 2U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_7_PIN,
			GET_BIT(Lu8_LCD_Command, 3U));
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_HIGH);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_LOW);
	Delay_vMilliSecond16MHzoscillator(2);
#endif
}

void HLCD_vWriteCharacter(u8 Lu8_LCD_Character) {
	MGPIO_WritePin(LCD_RS_PORT, LCD_RS_PIN, GPIO_HIGH); // Fetal operation if Low while "Data Transfer"
	//MGPIO_WritePin(LCD_RW_PIN, GPIO_LOW); // Held Low for "Write Operation"
	/**********************	_8_BIT_MODE	*************************/
#if LCD_MODE    ==   _8_BIT_MODE
	//MGPIO_WritePin(LCD_8BIT_DATA_PORT, LCD_DATA_0_PIN, GET_BIT(Lu8_LCD_Character, 0));
	MGPIO_WritePort(LCD_8BIT_DATA_PORT, Lu8_LCD_Character);
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_HIGH);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_LOW);
	Delay_vMilliSecond16MHzoscillator(2);

	/**********************	_4_BIT_MODE	*************************/
#elif LCD_MODE    ==   _4_BIT_MODE
	/***   Sending HIGH Nibble of 8 Bits Data   ***/
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_4_PIN,
			GET_BIT(Lu8_LCD_Character, 4U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_5_PIN,
			GET_BIT(Lu8_LCD_Character, 5U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_6_PIN,
			GET_BIT(Lu8_LCD_Character, 6U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_7_PIN,
			GET_BIT(Lu8_LCD_Character, 7U));
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_HIGH);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_LOW);
	Delay_vMilliSecond16MHzoscillator(2);
	/***   Sending LOW Nibble of 8 Bits Data    ***/
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_4_PIN,
			GET_BIT(Lu8_LCD_Character, 0U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_5_PIN,
			GET_BIT(Lu8_LCD_Character, 1U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_6_PIN,
			GET_BIT(Lu8_LCD_Character, 2U));
	MGPIO_WritePin(LCD_4BIT_DATA_PORT, LCD_DATA_7_PIN,
			GET_BIT(Lu8_LCD_Character, 3U));
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_HIGH);
	Delay_vMilliSecond16MHzoscillator(5);
	MGPIO_WritePin(LCD_EN_PORT, LCD_EN_PIN, GPIO_LOW);
	Delay_vMilliSecond16MHzoscillator(2);
#endif
}

void HLCD_vWriteString(u8 *Lu8_PTR_String) {
	u8 loc_U8_Counter = 0;
	while (Lu8_PTR_String[loc_U8_Counter] != '\0') {
		HLCD_vWriteCharacter(Lu8_PTR_String[loc_U8_Counter]);
		loc_U8_Counter++;
	}
}

void HLCD_vWriteOrignalNumber(f32 loc_F32_NUMBER) {
	s8 loc_S8_counter = 0;//must be S to include the -Ve counter state of -1 in (counter >= 0)
	s8 loc_S8_counter_copy = 0;	//makes a valid non changed state of counter to be compared
	u8 loc_U8_Float_Flag = 0;//indicates that the inserted number is float or non-float

	u8 POINT_POSITION = 1;		//indicates that the float point position 
	u8 loc_U8_Arr_Digit_Display[10] = { 0 };//the maximum digits for 32-bit number is ~ 10

	s32 loc_S32_Number_Copy = loc_F32_NUMBER;
	s32 loc_S32_FloatCast = (s32) loc_F32_NUMBER * FLOAT_RESELUTION; //integer powered copy 
	s32 loc_S32_FloatHold = loc_F32_NUMBER * FLOAT_RESELUTION; //float powered copy 

	if (loc_F32_NUMBER < 0) { //CHK for '-Ve' state
		HLCD_vWriteCharacter('-');
		loc_S32_Number_Copy = loc_S32_Number_Copy * (-1);	// -Ve ~ +Ve
		loc_S32_FloatHold = loc_S32_FloatHold * (-1);	// -Ve ~ +Ve
		loc_S32_FloatCast = loc_S32_FloatCast * (-1);	// -Ve ~ +Ve
	} else if (loc_F32_NUMBER == 0) { //CHK for '0' state
		HLCD_vWriteCharacter('0');
	} else {/*NOTHING*/
	}
	/****************************STORING PROCCES********************************/
	if (loc_S32_FloatHold > loc_S32_FloatCast) { //CHK for 'float' state
		loc_U8_Float_Flag = 1;
		if (loc_S32_FloatCast == 0) {
			HLCD_vWriteCharacter('0');
			HLCD_vWriteCharacter('.');
		} else {/*NOTHING*/
		}
		while (loc_S32_FloatHold != 0) { //inserting the digits to array from the 0-indx to the N-indx
			loc_U8_Arr_Digit_Display[loc_S8_counter] = loc_S32_FloatHold % 10;
			loc_S8_counter++;
			loc_S32_FloatHold = loc_S32_FloatHold / 10;
		}
		loc_S32_FloatCast = loc_S32_FloatCast / FLOAT_RESELUTION;
		while (loc_S32_FloatCast != 0) { //Detecting where's the float point exactly
			POINT_POSITION++;
			loc_S32_FloatCast = loc_S32_FloatCast / 10;
		}
	} else { //'integer' state
		loc_U8_Float_Flag = 0;
		while (loc_S32_Number_Copy != 0) { //inserting the digits to array from the 0-indx to the N-indx
			loc_U8_Arr_Digit_Display[loc_S8_counter] = loc_S32_Number_Copy % 10;
			loc_S8_counter++;
			loc_S32_Number_Copy = loc_S32_Number_Copy / 10;
		}
	}
	loc_S8_counter_copy = loc_S8_counter;
	loc_S8_counter--;
	/****************************PRINTING PROCCES********************************/
	while (loc_S8_counter >= 0) { //Displaying the digits while it's being stored backward
		HLCD_vWriteCharacter(
				loc_U8_Arr_Digit_Display[loc_S8_counter] + ASCII_NUM_INIT);
		loc_S8_counter--; //Escaping Counter
		if ((loc_S8_counter_copy - POINT_POSITION) == loc_S8_counter
				&& (loc_U8_Float_Flag == 1)) {
			//it doesn't apply for POINT_POSITION =1 , POINT_POSITION has to be >1 to be seen
			HLCD_vWriteCharacter('.');
		} else {/*NOTHING*/
		}
	}
}

void HLCD_vWriteNumber(s32 loc_S32_NUMBER) {
	u8 i = 0;
	u8 Storing_Array[10] = { 0 }; //no. of digits for U32 Number
	u32 loc_U32_Number_Copy = loc_S32_NUMBER;

	if (loc_S32_NUMBER < 0) { //CHK for '-Ve' state
		HLCD_vWriteCharacter('-');
		loc_S32_NUMBER = loc_S32_NUMBER * (-1);	// -Ve ~ +Ve
		loc_U32_Number_Copy = loc_S32_NUMBER;
	} else if (loc_U32_Number_Copy == 0) { //CHK for '0' state
		HLCD_vWriteCharacter('0');
	} else {/*NOTHING*/
	}

	while (loc_U32_Number_Copy) { //*STORING PROCCES*//
		Storing_Array[i] = (loc_U32_Number_Copy % 10) + '0';
		loc_U32_Number_Copy /= 10;
		i++;
	}
	while (i) {
		HLCD_vWriteCharacter(Storing_Array[i - 1]);
		i--;
	}
}

void HLCD_vWriteNumberFixedPosition(s32 loc_S32_NUMBER, u8 LinePostion,
		u8 Postion, u8 Width) {
	u8 i = 0;
	HLCD_vGoTo(LinePostion, Postion);
	for (i = 0; i < Width; i++) {
		HLCD_vWriteCharacter(' ');
	}
	HLCD_vGoTo(LinePostion, Postion);
	HLCD_vWriteNumber(loc_S32_NUMBER);
}

void HLCD_vClearScreen(void) {
	HLCD_vWriteCommand(LCD_COMMAND_CLEAR_SCREEN); //Refer to the command sheet "HAL_LCD_COMMANDS"
}

void HLCD_vGoTo(u8 Lu8_Row, u8 Lu8_Col) {
#if   LCD_DIMENSIONS   ==   LCD_2_BY_16
	u8 loc_Arr_RC_Commands[2] = {LCD_COMMAND_GOTO_1stLINE_POS_0,
		LCD_COMMAND_GOTO_2ndLINE_POS_0};
#elif LCD_DIMENSIONS   ==   LCD_4_BY_16
	u8 loc_Arr_RC_Commands[4] = { LCD_COMMAND_GOTO_1stLINE_POS_0,
	LCD_COMMAND_GOTO_2ndLINE_POS_0,
	LCD_COMMAND_GOTO_3ndLINE_POS_0,
	LCD_COMMAND_GOTO_4ndLINE_POS_0 };
#endif
	//Refer to the command sheet "HAL_LCD_COMMANDS"
	HLCD_vWriteCommand(loc_Arr_RC_Commands[Lu8_Row] + Lu8_Col);
}

void HLCD_vBuildCustomChar(u8 MemoryLocation, u8 CChar_Name) {
	u8 i = 0;
	u8 *CC_msg_Ptr = NULL;
	if (MemoryLocation < 8) {
		switch (CChar_Name) {
		case CHAR_HEART:
			CC_msg_Ptr = Char1;
			break;
		case CHAR_BATTARY:
			CC_msg_Ptr = Char2;
			break;
		case CHAR_RING:
			CC_msg_Ptr = Char3;
			break;
		case CHAR_SPEAKER:
			CC_msg_Ptr = Char4;
			break;
		case CHAR_MUSIC:
			CC_msg_Ptr = Char5;
			break;
		case CHAR_POWER_CABLE:
			CC_msg_Ptr = Char6;
			break;
		case CHAR_HAPPY_FACE:
			CC_msg_Ptr = Char7;
			break;
		default:
			break;
		}
		HLCD_vWriteCommand(0x40 + (MemoryLocation * 8));
		/* Command 0x40 and onwards forces the device to point CGRAM address */
		for (i = 0; i < 8; i++) /* Write 8 byte for generation of 1 character */
		{
			HLCD_vWriteCharacter(CC_msg_Ptr[i]);
		}
	}
	/******************************************************************
	 * 1- You have to build your custom char directly after LCD init
	 * 2- CGRAM can contain only 8 CChar starting from location (0, to 7)
	 * 3- break operation with CGRAM by going Home or GoTo(0,0)
	 * 4- Calling the CC from CGRAM by sending 0 to 7
	 * HLCD_vInitiate();
	 * HLCD_vWriteCustomChar(0, Character1);
	 * HLCD_vWriteCustomChar(1, Character2);
	 * HLCD_vWriteCharacter(0); without ''
	 * HLCD_vWriteCharacter(1);
	 ****************************************************************/
}
