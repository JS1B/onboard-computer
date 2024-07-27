#include <stdio.h>
#include "pico/stdlib.h"

#include "led_controller.h"
#include "bldc_motor.h"

#define OK_MSG "OK\n"

int main(void) {
    stdio_init_all();

    printf("Setting up...\n");
    printf("LED... ");
    LedController led;
    led.setBrightness(20);
    led.indicateFault();
    printf(OK_MSG);

    printf("Bldc motor... ");
    BLDCMotor motor(22, 50, 5.2f, 11.40f);
    motor.init();
    printf(OK_MSG);

    led.indicateIdle();

    sleep_ms(2000);

    float speed = 0.0f;

    printf("Starting running\n");
    while (true) {
        printf("Setting speed to %f\n", speed);
        motor.setSpeed(speed);

        sleep_ms(2000);
    }
    return 0;
}