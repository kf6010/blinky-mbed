#include "mbed.h"
 
/* for pinnames see https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 * for schematic see
 * https://github.com/ARMmbed/mbed-HDK/blob/master/Production%20Design%20Projects/ARM-mbed/ApplicationShield/v1.0.0/ApplicationShield%20V_1_0_0-SCH.pdf
 */

/* Create a Digital-output for the K64F Red led
 * The initial value defaults to 0 -- led is on
 */
DigitalOut led1(LED_RED); 
 
int main() {
    while (true) {  /* while _super-loop_ */
        led1 = !led1; /* toggle led state */
        wait(0.5);    /* pause for 0.5s */
    }
}
 
