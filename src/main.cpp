#include "mbed.h"
#include "C12832.h"
#include <stdio.h>
 
DigitalOut led1(LED1);
DigitalOut led2(LED2,1);

AnalogIn   pot1(A0);
AnalogIn   pot2(A1);


/* Pin Configuration for FRDM-K64F */
C12832 lcd(D11, D13, D12, D7, D10);

int main() {
    lcd.cls();
    lcd.locate(0,0);
    lcd.printf("Hello worlda\n");

    while (true) {
        led1 = !led1;
        led2 = !led2;

        lcd.locate(0,1);
        lcd.printf("Pot 1 : %.2f\n", (float)pot1);
        lcd.printf("Pot 2 : %.2f\n", (float)pot2);

        wait(0.5);
    }
}
 
