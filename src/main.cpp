#include "mbed.h"
 
/* for pinnames see
 * https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 */
DigitalOut led1(LED1);
 
int main() {
    while (true) {
        led1 = !led1;
        wait(0.5);
    }
}
 
