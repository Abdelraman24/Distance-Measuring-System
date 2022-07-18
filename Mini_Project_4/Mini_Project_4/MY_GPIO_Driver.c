/************************************************************************
 * Module: GPIO
 *
 * File Name: MY_GPIO_Driver.C
 *
 * Description: Source file for the ATmega16 GPIO driver
 *
 * Author: Abdelrahman Diaa-Eldein Sayd
 *
 *  Created on: 19/5/2022
 *
 ***********************************************************************/
#include <avr/io.h>
#include "MY_GPIO_Driver.h"
#include "COMMON_MACROS.h"



/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/



void GPIO_setupPinDirection(uint8 port_num, uint8 pin_num ,GPIO_PinDirectionType direction)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if(port_num>=NUM_OF_PORTS || pin_num>=NUM_OF_PINS_PER_PORT)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the pin direction as required */
		switch (port_num)
		{
		case PORTA_ID:

			if (direction==PIN_INPUT)
			{
				CLEAR_BIT(DDRA,pin_num);
			}
			else
				SET_BIT(DDRA,pin_num);
			break;
		case PORTB_ID:

			if (direction==PIN_INPUT)
			{
				CLEAR_BIT(DDRB,pin_num);
			}
			else
				SET_BIT(DDRB,pin_num);
			break;
		case PORTC_ID:

			if (direction==PIN_INPUT)
			{
				CLEAR_BIT(DDRC,pin_num);
			}
			else
				SET_BIT(DDRC,pin_num);
			break;
		case PORTD_ID:

			if (direction==PIN_INPUT)
			{
				CLEAR_BIT(DDRD,pin_num);
			}
			else
				SET_BIT(DDRD,pin_num);
			break;
		}
	}
}

void GPIO_writePin(uint8 port_num ,uint8 pin_num ,uint8 value)
{
	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if(port_num>=NUM_OF_PORTS || pin_num>=NUM_OF_PINS_PER_PORT)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the pin value as required */
		switch (port_num)
		{
		case PORTA_ID:

			if (value==LOGIC_LOW)
			{
				CLEAR_BIT(PORTA,pin_num);
			}
			else
				SET_BIT(PORTA,pin_num);
			break;
		case PORTB_ID:

			if (value==LOGIC_LOW)
			{
				CLEAR_BIT(PORTB,pin_num);
			}
			else
				SET_BIT(PORTB,pin_num);
			break;
		case PORTC_ID:

			if (value==LOGIC_LOW)
			{
				CLEAR_BIT(PORTC,pin_num);
			}
			else
				SET_BIT(PORTC,pin_num);
			break;
		case PORTD_ID:

			if (value==LOGIC_LOW)
			{
				CLEAR_BIT(PORTD,pin_num);
			}
			else
				SET_BIT(PORTD,pin_num);
			break;
		}
	}
}

uint8 GPIO_readPin(uint8 port_num ,uint8 pin_num)
{
	uint8 pin_value = LOGIC_LOW;


	/*
	 * Check if the input port number is greater than NUM_OF_PINS_PER_PORT value.
	 * Or if the input pin number is greater than NUM_OF_PINS_PER_PORT value.
	 * In this case the input is not valid port/pin number
	 */
	if(port_num>=NUM_OF_PORTS || pin_num>=NUM_OF_PINS_PER_PORT)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the pin value as required */
		switch (port_num)
		{
		case PORTA_ID:

			if (BIT_IS_SET(PINA,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
				pin_value = LOGIC_LOW;
			break;
		case PORTB_ID:

			if (BIT_IS_SET(PINB,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
				pin_value = LOGIC_LOW;
			break;
		case PORTC_ID:

			if (BIT_IS_SET(PINC,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
				pin_value = LOGIC_LOW;
			break;
		case PORTD_ID:

			if (BIT_IS_SET(PIND,pin_num))
			{
				pin_value = LOGIC_HIGH;
			}
			else
				pin_value = LOGIC_LOW;
			break;
		}
	}
	return pin_value;
}

void GPIO_setupPortDirection(uint8 port_num,GPIO_PortDirectionType direction)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num>=NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Setup the port direction as required */
		switch (port_num)
		{
		case PORTA_ID:

			DDRA=direction;
			break;

		case PORTB_ID:

			DDRB=direction;
			break;

		case PORTC_ID:

			DDRC=direction;
			break;

		case PORTD_ID:

			DDRD=direction;
			break;

		}
	}
}

void GPIO_writePort(uint8 port_num,uint8 value)
{
	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num>=NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Write the port value as required */
		switch (port_num)
		{
		case PORTA_ID:

			PORTA=value;
			break;

		case PORTB_ID:

			PORTB=value;
			break;

		case PORTC_ID:

			PORTC=value;
			break;

		case PORTD_ID:

			PORTD=value;
			break;

		}
	}
}

uint8 GPIO_readPort(uint8 port_num)
{
	uint8 port_value = LOGIC_LOW;


	/*
	 * Check if the input number is greater than NUM_OF_PORTS value.
	 * In this case the input is not valid port number
	 */
	if(port_num>=NUM_OF_PORTS)
	{
		/* Do Nothing */
	}
	else
	{
		/* Read the port value as required */
		switch (port_num)
		{
		case PORTA_ID:

			port_value = PINA;
			break;

		case PORTB_ID:

			port_value = PINB;
			break;

		case PORTC_ID:

			port_value = PINC;
			break;

		case PORTD_ID:

			port_value = PIND;
			break;

		}
	}
	return port_value;
}
