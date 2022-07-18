/************************************************************************
 *  Module: ICU
 *
 *  File Name: MY_ICU_Driver.h
 *
 *  Description: Header file for the AVR ICU driver
 *
 *  Author: Abdelrahman Diaa-Eldein
 *
 *  Created on: 22/5/2022
 *
 ***********************************************************************/

#ifndef MY_ICU_DRIVER_H_
#define MY_ICU_DRIVER_H_

#include "MY_std_types.h"


/*******************************************************************************
 *                         Types Declaration                                   *
 *******************************************************************************/


typedef enum {
	FALLING,RISING
}ICU_edgeType;


typedef enum {
	NO_CLOCK,F_CPU_CLOCK,F_CPU_8,F_CPU_64,F_CPU_256,F_CPU_1024
}ICU_clockSelect;


typedef struct {

	ICU_edgeType edge;
	ICU_clockSelect clock;
}ICU_ConfigType;


/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/


/*
 * Description : Function to initialize the ICU driver
 * 	1. Set the required clock.
 * 	2. Set the required edge detection.
 * 	3. Enable the Input Capture Interrupt.
 * 	4. Initialize Timer1 Registers
 */
void ICU_init(const ICU_ConfigType * Config_Ptr);

/*
 * Description: Function to set the required edge detection.
 */
void ICU_setEdgeDetectionType(const ICU_edgeType edgeType);

/*
 * Description: Function to set the Call Back function address.
 */
void ICU_SetCallBackFunction(void (* callBack_ptr) (void));

/*
 * Description: Function to get the Timer1 Value when the input is captured
 *              The value stored at Input Capture Register ICR1
 */
uint16 ICU_getInputCaptureValue(void);

/*
 * Description: Function to clear the Timer1 Value to start count from ZERO
 */
void ICU_clearTimerValue(void);

/*
 * Description: Function to disable the Timer1 to stop the ICU Driver
 */
void ICU_DeInit(void);

#endif /* MY_ICU_DRIVER_H_ */
