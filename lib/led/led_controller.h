#ifndef LED_CONTROLLER_H
#define LED_CONTROLLER_H

#include "rgb_led.h"
#include "on_off_led.h"

class LedController {
public:
    LedController();
    ~LedController();
    void setBrightness(uint8_t brightness);

    void indicateSuccess();
    void indicateWarning();
    void indicateFault();
    void indicateIdle();

private:
    enum Type {
        RGB,
        ON_OFF
    } type;

    union {
        RGBLed* rgbLed;
        OnOffLed* onOffLed;
    };
};

#endif // LED_CONTROLLER_H