#include <stdio.h>
#include "pico/stdlib.h"

int main(void)
{
    const uint LED_PIN = 16;

    stdio_init_all();

    gpio_init(LED_PIN);
    gpio_set_dir(LED_PIN, GPIO_OUT);

    uint32_t count = 0;
    while (true)
    {
        count++;
        if (!(count % 10000000)) {
            printf("C %u\n", count);
            gpio_put(LED_PIN, 1);
            sleep_ms(100);
            gpio_put(LED_PIN, 0);
        }
        // sleep_ms(10);
    }

    return 0;
}