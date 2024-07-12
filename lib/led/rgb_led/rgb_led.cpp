#include "rgb_led.h"

RGBLed::RGBLed(PIO pio, uint sm, uint pin, uint freq)
    : pio(pio), sm(sm) {
    this->offset = pio_add_program(pio, &ws2812_program);

    this->state = { 0, 0, 0, 255 };

    ws2812_program_init(pio, sm, offset, pin, freq, true);
}

void RGBLed::setColor(uint8_t red, uint8_t green, uint8_t blue) {
    this->state.red = red;
    this->state.green = green;
    this->state.blue = blue;
}

void RGBLed::setBrightness(uint8_t brightness) {
    this->state.brightness = brightness;
}

void RGBLed::putPixel(uint32_t pixel_rgb) {
    pio_sm_put_blocking(this->pio, this->sm, pixel_rgb << 8u);
}

void RGBLed::update(void) {
    RGBLed::State s = this->state;
    uint32_t mask = (s.green * s.brightness / 255 << 16) | (s.red * s.brightness / 255 << 8) | (s.blue * s.brightness / 255 << 0);
    this->putPixel(mask);
}