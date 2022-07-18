 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: MY_LCD_Driver.c
 *
 * Description: Source file for the LCD driver
 *
 * Author: Abdelrahman Diaa-ELdein
 *
 *Date: 20/5/2022
 *
 *******************************************************************************/

#include "MY_LCD_Driver.h"
#include "COMMON_MACROS.h"
#include "MY_GPIO_Driver.h"
#include <util/delay.h>
#include <stdlib.h>



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void LCD_init(void)
{
	GPIO_setupPinDirection(LCD_RW_PORT_ID,LCD_RW_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_RS_PORT_ID,LCD_RS_PIN_ID,PIN_OUTPUT);
	GPIO_setupPinDirection(LCD_E_PORT_ID,LCD_E_PIN_ID,PIN_OUTPUT);

	GPIO_setupPortDirection(LCD_DATA_PORT_ID,PORT_OUTPUT);

	LCD_sendCommand(LCD_TWO_LINES_EIGHT_BITS_MODE);
	LCD_sendCommand(LCD_CURSOR_OFF);
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_sendCommand(uint8 command)
{
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID , LOGIC_LOW);
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID , LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID , LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT_ID,command);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID , LOGIC_LOW);
	_delay_ms(1);

}

void LCD_displayCharacter(uint8 character)
{
	GPIO_writePin(LCD_RS_PORT_ID,LCD_RS_PIN_ID , LOGIC_HIGH);
	GPIO_writePin(LCD_RW_PORT_ID,LCD_RW_PIN_ID , LOGIC_LOW);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID , LOGIC_HIGH);
	_delay_ms(1);
	GPIO_writePort(LCD_DATA_PORT_ID,character);
	_delay_ms(1);
	GPIO_writePin(LCD_E_PORT_ID,LCD_E_PIN_ID , LOGIC_LOW);
	_delay_ms(1);
}

void LCD_displayString(char* string)
{
	for(uint8 i=0;string[i]!='\0';i++)
	{
		LCD_displayCharacter(string[i]);
	}
}

void LCD_moveCursor(uint8 row,uint8 col)
{

	uint8 lcd_position;
	switch(row)
	{
	case 0:
		lcd_position=col;
		break;
	case 1:
		lcd_position=col + 0x40;
		break;
	case 2:
		lcd_position=col + 0x10;
		break;
	case 3:
		lcd_position=col + 0x50;
		break;
	}
	LCD_sendCommand(lcd_position | LCD_SET_CURSOR_LOCATION);
}

void LCD_displayStringRowColumn(char* string,uint8 row,uint8 col)
{
	LCD_moveCursor( row , col );
	LCD_displayString(string);
}

void LCD_clearScreen(void)
{
	LCD_sendCommand(LCD_CLEAR_COMMAND);
}

void LCD_intgerToStringDisplay(int data)
{
	char buff[16];
	itoa(data,buff,10);
	LCD_displayString(buff);
}
