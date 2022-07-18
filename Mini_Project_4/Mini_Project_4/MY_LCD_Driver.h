 /******************************************************************************
 *
 * Module: LCD
 *
 * File Name: MY_LCD_Driver.h
 *
 * Description: Header file for the LCD driver
 *
 * Author: Abdelrahman Diaa-ELdein
 *
 *******************************************************************************/

#ifndef MY_LCD_DRIVER_H_
#define MY_LCD_DRIVER_H_

#include "MY_std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


#define LCD_DATA_PORT_ID               PORTA_ID

#define LCD_RS_PORT_ID                 PORTB_ID
#define LCD_RS_PIN_ID                  PIN0_ID

#define LCD_RW_PORT_ID                 PORTB_ID
#define LCD_RW_PIN_ID                  PIN1_ID

#define LCD_E_PORT_ID                  PORTB_ID
#define LCD_E_PIN_ID                   PIN2_ID

#define LCD_CLEAR_COMMAND              0x01
#define LCD_GO_TO_HOME                 0x02
#define LCD_TWO_LINES_EIGHT_BITS_MODE  0x38
#define LCD_TWO_LINES_FOUR_BITS_MODE   0x28
#define LCD_CURSOR_OFF                 0x0C
#define LCD_CURSOR_ON                  0x0E
#define LCD_SET_CURSOR_LOCATION        0x80


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description :
 * Initialize the LCD:
 * 1. Setup the LCD pins directions by use the GPIO driver.
 * 2. Setup the LCD Data Mode 4-bits or 8-bits.
 */
void LCD_init(void);

/*
 * Description :
 * Send the required command to the screen
 */
void LCD_sendCommand(uint8 command);

/*
 * Description :
 * Display the required character on the screen
 */
void LCD_displayCharacter(uint8 character);

/*
 * Description :
 * Display the required string on the screen
 */
void LCD_displayString(char* string);

/*
 * Description :
 * Display the required string in a specified row and column index on the screen
 */
void LCD_displayStringRowColumn(char* string,uint8 row,uint8 col);

/*
 * Description :
 * Move the cursor to a specified row and column index on the screen
 */
void LCD_moveCursor(uint8 row,uint8 col);

/*
 * Description :
 * Send the clear screen command
 */
void LCD_clearScreen(void);

/*
 * Description :
 * Display the required decimal value on the screen
 */
void LCD_intgerToStringDisplay(int data);

#endif /* MY_LCD_DRIVER_H_ */
