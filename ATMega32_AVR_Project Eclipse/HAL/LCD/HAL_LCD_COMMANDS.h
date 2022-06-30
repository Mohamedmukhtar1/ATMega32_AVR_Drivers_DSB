/*
 * HAL_LCD_COMMANDS.h
 *
 * Created: 2022-04-10 05:51:51 PM
 *  Author: Eng- Mohamed Mokhtar
 */

#ifndef HAL_LCD_COMMANDS_H_
#define HAL_LCD_COMMANDS_H_

#define LCD_COMMAND_ACTIVATE_8_BITMODE			(0x38)

#define LCD_COMMAND_1_ACTIVATE_4_BITMODE		(0x33)
#define LCD_COMMAND_2_ACTIVATE_4_BITMODE		(0x32)
#define LCD_COMMAND_3_ACTIVATE_4_BITMODE		(0x28)

#define LCD_COMMAND_DISPLAY_ON_CURSOR_OFF		(0x0C)
#define LCD_COMMAND_CLEAR_SCREEN				(0x01)
#define LCD_COMMAND_RETURN_HOME_CLEAR_SCREEN	(0x02)
#define LCD_COMMAND_CURSOR_INCREMENT			(0x06)

#define LCD_COMMAND_GOTO_1stLINE_POS_0			(0x80)
#define LCD_COMMAND_GOTO_2ndLINE_POS_0			(0xC0)
#define LCD_COMMAND_GOTO_3ndLINE_POS_0			(0x90)	//94
#define LCD_COMMAND_GOTO_4ndLINE_POS_0			(0xD0)	//D4

#endif /* HAL_LCD_COMMANDS_H_ */

/*->>>>>>>>>>>>>>	LCD_COMMANDS_SHEET	<<<<<<<<<<<<<<-**
 0x38  -	Activate 8-bit mode
 0x33  -	Activate1 4-bit mode
 0x32  - Activate2 4-bit mode
 0x28  -	Activate3 4-bit mode													******
 0x01  -	Clear screen
 0x02  -	return home
 0x04  -	Cursor decrement
 0x05  -	Display shifts to right
 0x06  -	Cursor increment
 0x07  -	Display shifts to left
 0x08  -	Cursor and display OFF
 0x10  -	Cursor position Shifts to left
 0x14  -	Cursor position shifts to right
 0x38  -	Using two lines, 8-bit mode
 0x28  -	Using two lines, 4-bit mode							******
 0x0C  -	Display ON, cursor OFF
 0x0A  -	Display OFF, cursor ON
 0x0E  -	Display ON, cursor blinking
 0x30  -	For display in one line in 8-bit mode
 0x20  -	For display in one line in 4-bit mode
 0x0F  -	Display data on cursor blinking
 0x18  -	Shift complete data to left side
 0x1C  -	Shift complete data to right side
 
 0x80  - go to first  line position 0
 0x81  - go to first  line position 1
 0x82  - go to first  line position 2
 0xC0  - go to second line position 0
 0xC1  - go to second line position 1
 0xC2  - go to second line position 2
 */
