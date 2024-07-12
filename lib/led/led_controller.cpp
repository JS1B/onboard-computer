#include "led_controller.h"

LedController::LedController() {
#ifdef PICO_DEFAULT_WS2812_PIN
    this->type = RGB;
    this->rgbLed = new RGBLed(pio0, 0, PICO_DEFAULT_WS2812_PIN, 800000);
    this->rgbLed->update();
#else
    this->type = ON_OFF;
    this->onOffLed = new OnOffLed(PICO_DEFAULT_LED_PIN, false);
    this->onOffLed->update();
#endif
}

LedController::~LedController() {
    switch (this->type) {
    case LedController::Type::RGB:
        delete this->rgbLed;
        break;
    case LedController::Type::ON_OFF:
        delete this->onOffLed;
        break;
    }
}

void LedController::indicateSuccess() {
    switch (this->type) {
    case LedController::Type::RGB:
        this->rgbLed->setColor(0, 255, 0);
        this->rgbLed->update();
        break;
    case LedController::Type::ON_OFF:
        this->onOffLed->setState(true);
        this->onOffLed->update();
        break;
    }
}

void LedController::indicateWarning() {
    switch (this->type) {
    case LedController::Type::RGB:
        this->rgbLed->setColor(255, 255, 0);
        this->rgbLed->update();
        break;
    case LedController::Type::ON_OFF:
        this->onOffLed->setState(true);
        this->onOffLed->update();
        break;
    }
}

void LedController::indicateFault() {
    switch (this->type) {
    case LedController::Type::RGB:
        this->rgbLed->setColor(255, 0, 0);
        this->rgbLed->update();
        break;
    case LedController::Type::ON_OFF:
        this->onOffLed->setState(false);
        this->onOffLed->update();
        break;
    }
}

void LedController::indicateIdle() {
    switch (this->type) {
    case LedController::Type::RGB:
        this->rgbLed->setColor(0, 0, 255);
        this->rgbLed->update();
        break;
    case LedController::Type::ON_OFF:
        this->onOffLed->setState(false);
        this->onOffLed->update();
        break;
    }
}

void LedController::setBrightness(uint8_t brightness) {
    switch (this->type) {
    case LedController::Type::RGB:
        this->rgbLed->setBrightness(brightness);
        this->rgbLed->update();
        break;
    case LedController::Type::ON_OFF:
        break;
    }
}