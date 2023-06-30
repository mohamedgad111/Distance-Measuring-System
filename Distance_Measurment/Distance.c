


#include "ultrasonic.h"
#include "lcd.h"
#include <avr/io.h>
#include "gpio.h"
#include "common_macros.h"
#include "icu.h"
int main(void)
{
	SREG |= (1 << 7);
	LCD_init();  // initializing LCD
	Ultrasonic_init();  // Initializing Ultrasonic
	LCD_clearScreen();
	LCD_displayString("Distance=");
	uint16 Distance = 0;
	while (1)
	{
		Distance = Ultrasonic_readDistance();
		LCD_moveCursor(0, 0);
		LCD_displayString("Distance=");
		LCD_moveCursor(0, 10);
		if (Distance >= 100)
		{
			LCD_intgerToString(Distance);
		}
		else
		{
			LCD_intgerToString(Distance);
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		LCD_moveCursor(0, 13);
		LCD_displayString("cm");
	}
}
