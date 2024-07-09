#include "rgb_led.h"

RGBLED::RGBLED(PIO pio, uint sm, uint pin, uint freq)
    : pio(pio), sm(sm) {
    this->offset = pio_add_program(pio, &ws2812_program);

    State state = { 0, 0, 0, 255 };

    ws2812_program_init(pio, sm, offset, pin, freq, true);
}

void RGBLED::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    this->target.red = red;
    this->target.green = green;
    this->target.blue = blue;
}

void RGBLED::setBrightness(uint8_t brightness) {
    this->target.brightness = brightness;
}

void RGBLED::apply() {
    this->state = this->target;
    this->update();
}

void RGBLED::putPixel(uint32_t pixel_grb) {
    pio_sm_put_blocking(pio, sm, pixel_grb << 8u);
}

void RGBLED::update() {
    uint32_t mask = (state.green * state.brightness / 255 << 16) | (state.red * state.brightness / 255 << 8) | (state.blue * state.brightness / 255 << 0);
    this->putPixel(mask);
}