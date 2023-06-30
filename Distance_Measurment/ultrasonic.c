/*
 * ultrasonic.c
 *
 *  Created on: Jun 15, 2023
 *      Author: Mohamed Gad
 */

#include "icu.h"
#include "gpio.h"
#include "util/delay.h"
#include "ultrasonic.h"
/*     FUNCTIONS DEFINITIONS   */

uint8 EdgeCount = 0;
uint16 Time = 0;
uint16 Distance = 0;

void Ultrasonic_init(void) {
	ICU_ConfigType ICU_Config = { F_CPU_8, RAISING }; //Configuration Structure
	ICU_init(&ICU_Config);  // Initialization of ICU Driver
	ICU_setCallBack(&Ultrasonic_edgeProcessing); //Set Call Back Function
	GPIO_setupPinDirection(PORTB_ID, PIN5_ID, PIN_OUTPUT); //Trigger Pin Output

}

void Ultrasonic_Trigger(void) {
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_HIGH); // to send the pulse for 10us
	_delay_us(10);
	GPIO_writePin(PORTB_ID, PIN5_ID, LOGIC_LOW);
}

uint16 Ultrasonic_readDistance(void) {
	Ultrasonic_Trigger();
	EdgeCount=0;
		Distance= ((uint16)((float)Time)/(57.5)); // Calculating distance measure by ultrasonic

	return Distance;

}

void Ultrasonic_edgeProcessing(void) {
	EdgeCount++;
	if (EdgeCount == 1) {
		ICU_clearTimerValue();
		ICU_setEdgeDetectionType(FALLING);
	}
	if (EdgeCount == 2) {
		Time = ICU_getInputCaptureValue();
		ICU_setEdgeDetectionType(RAISING);
		ICU_clearTimerValue();
	}

}
