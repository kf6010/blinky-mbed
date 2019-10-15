#include "mbed.h"
 
/* for pinnames see https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 */

/* Create a Digital-output for the K64F Red led
 * The initial value defaults to 0 -- led is on
 */
DigitalOut red(LED_RED); 
 
int main() {
    while (true) {  /* while _super-loop_ */
        red = !red; /* toggle led state */
        wait(0.5);    /* pause for 0.5s */
    }
}
 
