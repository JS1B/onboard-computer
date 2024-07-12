#ifndef RGB_LED_H
#define RGB_LED_H

#include "hardware/pio.h"
#include "ws2812.pio.h"

class RGBLed {
public:
    RGBLed(PIO pio, uint sm, uint pin, uint freq);
    void setColor(uint8_t red, uint8_t green, uint8_t blue);
    void setBrightness(uint8_t brightness);
    void update();

private:
    struct State {
        uint8_t red;
        uint8_t green;
        uint8_t blue;
        uint8_t brightness;
    } state;

    PIO pio;
    uint sm;
    uint offset;

    void putPixel(uint32_t pixel_rgb);
};

#endif // RGB_LED_H