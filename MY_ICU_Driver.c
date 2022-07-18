/************************************************************************
 *  Module: ICU
 *
 *  File Name: MY_ICU_Driver.c
 *
 *  Description: Source file for the AVR ICU driver
 *
 *  Author: Abdelrahman Diaa-Eldein
 *
 *  Created on: 22/5/2022
 *
 ***********************************************************************/

#include "MY_ICU_Driver.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "COMMON_MACROS.h"


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

/* Global variables to hold the address of the call back function in the application */
static volatile void (*ptr)(void) = NULL_PTR;


/*******************************************************************************
 *                       Interrupt Service Routines                            *
 *******************************************************************************/

ISR(TIMER1_CAPT_vect)
{
	if(ptr != NULL_PTR)
	{
		(*ptr)();
	}
}


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void ICU_init(const ICU_ConfigType * Config_Ptr)
{
	CLEAR_BIT(DDRD,PD6);  /* Configure ICP1/PD6 as i/p pin */
	SET_BIT(TCCR1A,FOC1B);
	SET_BIT(TCCR1A,FOC1A);

	/*
     * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & ~(1<<6)) | (Config_Ptr->edge<<6);

	/*
	 * insert the required clock value in the first three bits (CS10, CS11 and CS12)
	 * of TCCR1B Register
	 */
    TCCR1B = (TCCR1B & ~(7)) | (Config_Ptr->clock);

	TCNT1=0;   /* Initial Value for Timer1 */
	ICR1=0;    /* Initial Value for the input capture register */

	/* Enable the Input Capture interrupt to generate an interrupt when edge is detected on ICP1/PD6 pin */
	SET_BIT(TIMSK,TICIE1);
}


void ICU_setEdgeDetectionType(const ICU_edgeType edgeType)
{
	/*
	 * insert the required edge type in ICES1 bit in TCCR1B Register
	 */
	TCCR1B = (TCCR1B & ~(1<<6)) | (edgeType<<6);
}

void ICU_SetCallBackFunction(void (* callBack_ptr) (void))
{
	/* Save the address of the Call back function in a global variable */
	ptr=callBack_ptr;
}

uint16 ICU_getInputCaptureValue(void)
{
	return ICR1;
}

void ICU_clearTimerValue(void)
{
	TCNT1=0;
}

void ICU_DeInit(void)
{
	TCCR1A=0;
	TCCR1B=0;
	TCNT1=0;
	ICR1=0;
	CLEAR_BIT(TIMSK,TICIE1);
}

