#include "on_off_led.h"

OnOffLed::OnOffLed(uint pin, bool inverted)
    : pin(pin), inverted(inverted) {
    gpio_init(pin);
    gpio_set_dir(pin, GPIO_OUT);
}

void OnOffLed::setState(bool enabled) {
    this->state = enabled;
}

void OnOffLed::update(void) {
    bool s = this->state ^ this->inverted;

    gpio_put(this->pin, s);
}