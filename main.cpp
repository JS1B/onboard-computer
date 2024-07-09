#include <stdio.h>
#include "pico/stdlib.h"
#include "rgb_led.h"

int main(void) {
    stdio_init_all();

    PIO pio = pio0;
    int sm = 0;

    RGBLED led(pio, sm, PICO_DEFAULT_WS2812_PIN, 800000);
    led.setBrightness(20);

    while (true) {
        led.setColor(0, 255, 0);
        led.apply();
        sleep_ms(1000);

        led.setColor(255, 0, 0);
        led.apply();
        sleep_ms(1000);

        led.setColor(0, 0, 255);
        led.apply();
        sleep_ms(1000);

    }
    return 0;
}