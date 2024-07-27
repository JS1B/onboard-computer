#ifndef BLDC_MOTOR_H
#define BLDC_MOTOR_H

#include "pico/stdlib.h"

class BLDCMotor {
public:
    BLDCMotor(uint pwm_pin, uint32_t freq_hz = 50, float min_duty = 5.2f, float max_duty = 11.40f);
    ~BLDCMotor();

    void init();
    void setSpeed(float speed); // Fraction 0.0 - 100.0
    float getSpeed();
    void stop();

private:
    uint pwm_pin;
    uint slice_num;
    uint channel;
    uint32_t freq_hz;
    float speed;

    float min_duty_frac;
    float max_duty_frac;

    void setPwmDutyCycle(uint16_t duty_cycle);
};

#endif // BLDC_MOTOR_H