#include "mbed.h"
/* for pinnames see
 * https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 *  * for schematic see
 *   *
 *   https://github.com/ARMmbed/mbed-HDK/blob/master/Production%20Design%20Projects/ARM-mbed/ApplicationShield/v1.0.0/ApplicationShield%20V_1_0_0-SCH.pdf
 *    */

/* Create a Digital-output for the K64F Red led
 *  * The initial value defaults to 0 -- led is on
 *   */
DigitalOut led1(LED_RED); 
 
/* for pinnames see
 * https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 */
DigitalOut led1(LED_RED);

/* Green LED is on pin D9
 * see https://os.mbed.com/components/mbed-Application-Shield/
 * 
 */
DigitalOut led2(D9,1);
 
int main() {
    while (true) {
        led1 = !led1;
        led2 = !led2;
        wait(0.5);
    }
}
 
