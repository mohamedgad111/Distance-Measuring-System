/*
 * ultrasonic.h
 *
 *  Created on: Jun 15, 2023
 *      Author: Mohamed Gad
 */

#ifndef ULTRASONIC_H_
#define ULTRASONIC_H_
#include "std_types.h"

/*   FUNCTIONS PROTOTYPES   */

 void Ultrasonic_init(void);
 void Ultrasonic_Trigger(void);
 uint16 Ultrasonic_readDistance(void);
 void Ultrasonic_edgeProcessing(void);


#endif /* ULTRASONIC_H_ */
