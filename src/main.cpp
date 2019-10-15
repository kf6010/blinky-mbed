#include "mbed.h"
#include "C12832.h"
#include "MMA7660.h"
#include <stdio.h>

/* for pinnames see
 * https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 */

/* Application Shield
 * see https://os.mbed.com/components/mbed-Application-Shield/
 * The "Details" section about two-thirds down lists the pin connections
 *
 * for schematic see
 * https://github.com/ARMmbed/mbed-HDK/blob/master/Production%20Design%20Projects/ARM-mbed/ApplicationShield/v1.0.0/ApplicationShield%20V_1_0_0-SCH.pdf
 */

/* Create a Digital-output for the K64F Red led
 * The initial value defaults to 0 -- led is on
 */
DigitalOut red(LED_RED); 
 
/* Application shield Green LED is on pin D9
 * see https://os.mbed.com/components/mbed-Application-Shield/
 * The connection is pin=0 LED=on
 * Set initial value to 1 -- led is off
 */
DigitalOut AS_Green(D9,1);

/* Need to set Application shield RED led off
 * LED is on pin D5 -- set initial value to 1
 */
DigitalOut AS_Red(D5,1);

 
/* Lcd
 * Pin Configuration for FRDM-K64F */
C12832 lcd(D11, D13, D12, D7, D10);

/* Potentiometers are connected to Analogue inputs
 * A0 and A1
 */
AnalogIn Left_pot(A0);
AnalogIn Right_pot(A1);

/* Joystick switches on Application shield
 * pins are connected such that pressed reads as a 1
 *     down:A3
 *     left:A4
 *   centre:D4
 *       up:A2
 *    right:A5
 *
 * We can use the array initialisation of objects
 */
DigitalIn joystick[5] = { D4, A2, A3, A4, A5};
char       symbols[5] = {'C','U','D','L','R'};

/* Accelerometer
 * FRDM I2C connection
 */
MMA7660 accel(I2C_SDA, I2C_SCL);

int main() {
    lcd.cls();                  /* clear the screen */
    lcd.locate(0,0);            /* position at top-left corner */

    while (true) { /* super loop */
		int i;
		char js_symb = '-';/* default value for when not pressed */
        red = !red;
        AS_Green = !AS_Green;

		/* scan through joystick switches */
		for( i=0 ; i<5 ; i++) {
			if( joystick[i] ) {/*if joystick pressed */
				js_symb = symbols[i]; /* set symbol indicator */
			}
		}

        lcd.locate(0,0);  /* position at top left corner */
        lcd.printf(" Left Pot: %.2f\n", (float)Left_pot);
        lcd.printf("Right Pot: %.2f\n", (float)Right_pot);
		lcd.printf(" joystick: %c\n", js_symb);

		lcd.locate(72,0); /* half way across the top */
		lcd.printf("Acc x: %.2f", accel.x() );
		lcd.locate(72,8); /* half way across one row down */
		lcd.printf("Acc x: %.2f", accel.y() );
		lcd.locate(72,16); /* half way across two rows down */
		lcd.printf("Acc x: %.2f", accel.z() );

        wait(0.5);
    }
}

