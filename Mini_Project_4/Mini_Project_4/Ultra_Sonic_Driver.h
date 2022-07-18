/************************************************************************
 *  Module: UltraSonic Driver
 *
 *  File Name: Ultra_Sonic_Driver.h
 *
 *  Description: Header file for UltraSonic Sensor Driver using AVR
 *
 *  Author: Abdelrahman Diaa-Eldein
 *
 *  Created on: 13/7/2022
 *
 ***********************************************************************/


#ifndef ULTRA_SONIC_DRIVER_H_
#define ULTRA_SONIC_DRIVER_H_

#include "MY_std_types.h"


/*******************************************************************************
 *                                Definitions                                  *
 *******************************************************************************/


#define ULTRASONIC_TRIGGER_PORT   PORTB_ID
#define ULTRASONIC_TRIGGER_PIN    PIN5_ID


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description : Function to initialize the Ultrasonic sensor driver
 * 	1. Initialize the ICU driver as required. ->The ICU should be configured
 * 		with frequency F_CPU/8 and to detect the raising edge
 * 		as the first edge.
 * 	2. Setup the ICU call back function.
 * 	3. Setup the direction for the trigger pin as output pin through the GPIO driver
 */
void Ultrasonic_init(void);

/*
 * Description :
 * 				Send the Trigger pulse to the ultrasonic.
 */
void Ultrasonic_trigger(void);

/*
 * Description :
 * 				1- Send the trigger pulse by using Ultrasonic_Trigger function
 * 				2- Start the measurements by the ICU from this moment.
 */
uint16 Ultrasonic_readDistance(void);

/*
 * Description :
 * 				1- This is the call back function called by the ICU driver.
 * 				2- This is used to calculate the high time (pulse time) generated by the ultrasonic sensor.
 */
void Ultrasonic_edgeProcessing(void);


#endif /* ULTRA_SONIC_DRIVER_H_ */