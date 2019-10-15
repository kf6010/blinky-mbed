#include "mbed.h"
 
/* for pinnames see
 * https://os.mbed.com/teams/Freescale/wiki/frdm-k64f-pinnames
 */
DigitalOut led1(LED1);
DigitalOut led2(LED2,1);
 
int main() {
    while (true) {
        led1 = !led1;
        led2 = !led2;
        wait(0.5);
    }
}
 
