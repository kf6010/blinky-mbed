#include "mbed.h"
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

int main() {
    while (true) {    /* super loop */
        red = !red;
        AS_Green = !AS_Green;
        wait(0.5);
    }
}
 
