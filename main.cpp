#include <stdio.h>
#include "pico/stdlib.h"
#include "led_controller.h"

int main(void) {
    stdio_init_all();

    LedController led;
    led.setBrightness(20);

    while (true) {
        printf("Test\n");
        led.indicateSuccess();
        sleep_ms(100);
        led.indicateWarning();
        sleep_ms(100);
        led.indicateIdle();
        sleep_ms(100);
        led.indicateFault();
        sleep_ms(100);
    }
    return 0;
}