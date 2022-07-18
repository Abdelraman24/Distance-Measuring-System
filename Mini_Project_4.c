/**
 ===================================================================================================
 Name        : Mini Project 4

 Author      : Abdelrahman Diaa-Eldein

 Description : Measuring distance using ultraSonic sensor (Based on layered architecture mode)

 Date        : 13/7/2022
 ===================================================================================================
 **/



#include "MY_LCD_Driver.h"         /*include the header file of the LCD*/
#include "Ultra_Sonic_Driver.h"    /*include the header file of the UltraSonic Sensor*/
#include <avr/io.h>                /*AVR Library To use the SREG register */
#include <util/delay.h>            /*Delay Library To use Delay Functions */


int main()
{
	uint16 Distance = 0;  /* Variable to store the measured distance*/

	/* Enable Global Interrupt I-Bit */
	SREG |= (1<<7);

	/* Initialize both the LCD and UltraSonic driver */
	LCD_init();
	Ultrasonic_init();

	/* Display this string "Distance=     Cm" only once on LCD  */
	LCD_displayString("Distance=     Cm");

	while(1)
	{
		Distance = Ultrasonic_readDistance();

		/* display the Measured distance on LCD screen */
		LCD_moveCursor(0,10);
		LCD_intgerToStringDisplay(Distance+1);


		/* In case the digital value is two or one digits print space in the next digit place*/
		if (Distance<100)
		{
			LCD_displayCharacter(' ');
		}

		_delay_ms(100);
	}

}
