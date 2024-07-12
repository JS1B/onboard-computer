#ifndef ON_OFF_LED_H
#define ON_OFF_LED_H

#include "hardware/gpio.h"

class OnOffLed {
public:
    OnOffLed(uint pin, bool inverted = false);
    void setState(bool enabled);
    void update();

private:
    bool state;
    uint pin;
    bool inverted;
};

#endif // ON_OFF_LED_H