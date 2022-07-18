/************************************************************************
 *  Module: UltraSonic Driver
 *
 *  File Name: Ultra_Sonic_Driver.c
 *
 *  Description: Source file for UltraSonic Sensor Driver using AVR
 *
 *  Author: Abdelrahman Diaa-Eldein
 *
 *  Created on: 13/7/2022
 *
 ***********************************************************************/

#include "Ultra_Sonic_Driver.h"
#include "MY_ICU_Driver.h"
#include "MY_GPIO_Driver.h"
#include <util/delay.h>


/*******************************************************************************
 *                           Global Variables                                  *
 *******************************************************************************/

uint8 g_edgeCount = 0;
uint16 g_timeMeasured = 0;
uint16 Distance=0;


/* Configuration Structure for ICU init function to setup both the required edge
 * detection type and the prescalar
 */
ICU_ConfigType Icu_config ={RISING,F_CPU_8};


/*******************************************************************************
 *                      Functions Definitions                                  *
 *******************************************************************************/


void Ultrasonic_init(void)
{
	/*Configure and initialize the ICU driver*/
	ICU_init(&Icu_config);

	ICU_SetCallBackFunction(Ultrasonic_edgeProcessing);

	/*Setup the direction for the trigger pin as output pin through the GPIO driver*/
	GPIO_setupPinDirection(ULTRASONIC_TRIGGER_PORT, ULTRASONIC_TRIGGER_PIN ,PIN_OUTPUT);

}


void Ultrasonic_trigger(void)
{
	/* Send the trigger pulse by out high on the trigger pin for 10us
	 * and then out low on it
	 */
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN , LOGIC_HIGH);
	_delay_us(10);
	GPIO_writePin(ULTRASONIC_TRIGGER_PORT,ULTRASONIC_TRIGGER_PIN , LOGIC_LOW);
}


uint16 Ultrasonic_readDistance(void)
{
	Ultrasonic_trigger(); /* Send the trigger pulse*/

	 /*
	  * Sound velocity = 340.00 m/s = 34000 cm/s
	  *
	  * Distance=Time*Speed
	  *
	  * Required distance=Total Distance/2
	  *
	  * Now, here we have selected an internal 8MHz oscillator frequency for ATmega16,
	  * with Prescaler F_CPU/8 for timer frequency. Then time to execute 1 instruction is 1 us.
	  * So, the timer gets incremented after 1 us time
	  *  = 17000 x (TIMER value) x 1 x 10^-6 cm = 0.017 x (TIMER value) cm
	  *  = (TIMER value) / 58.8 cm Note TIMER VALUE is the time calculated by the ICU.
	  */
	Distance = g_timeMeasured / 58 ;

	return Distance;
}


void Ultrasonic_edgeProcessing(void)
{
	g_edgeCount++;
	if(g_edgeCount == 1)
	{
		/*
		 * Clear the timer counter register to start measurements from the
		 * first detected rising edge
		 */
		ICU_clearTimerValue();

		/* Detect falling edge */
		ICU_setEdgeDetectionType(FALLING);
	}
	else if(g_edgeCount == 2)
	{
		/* Store the High time value */
		g_timeMeasured = ICU_getInputCaptureValue();

		/* Detect rising edge */
		ICU_setEdgeDetectionType(RISING);

		g_edgeCount = 0;
	}

}

