#include "bldc_motor.h"

#include "hardware/pwm.h"
#include "hardware/clocks.h"

#include "pwm_helper.h"

BLDCMotor::BLDCMotor(uint pwm_pin, uint32_t freq_hz, float min_duty_frac, float max_duty_frac)
    : pwm_pin(pwm_pin), freq_hz(freq_hz), speed(0.0f), min_duty_frac(min_duty_frac), max_duty_frac(max_duty_frac) {
    slice_num = pwm_gpio_to_slice_num(pwm_pin);
    channel = pwm_gpio_to_channel(pwm_pin);
}

BLDCMotor::~BLDCMotor() {
    this->stop();
}

void BLDCMotor::init() {
    gpio_set_function(this->pwm_pin, GPIO_FUNC_PWM);

    pwm_clock_params params = pwm_determine_params(this->freq_hz, clock_get_hz(clk_sys), round_mode::round_up);

    pwm_set_wrap(this->slice_num, params.wrap);
    pwm_set_chan_level(this->slice_num, this->channel, 0);
    pwm_set_clkdiv(this->slice_num, params.clock_div);
    pwm_set_enabled(this->slice_num, true);

    this->setSpeed(this->speed);
}

void BLDCMotor::setSpeed(float speed) {
    assert(speed <= 100.0f);
    this->speed = speed;

    // Map it between the min max values so the motor can react to it
    // output = output_start + ((output_end - output_start) / (input_end - input_start)) * (input - input_start)
    uint16_t min_duty = UINT16_MAX * this->min_duty_frac / 100.0f;
    uint16_t max_duty = UINT16_MAX * this->max_duty_frac / 100.0f;
    uint16_t duty_cycle = min_duty + ((max_duty - min_duty) * speed / 100.0f);

    this->setPwmDutyCycle(duty_cycle);
}

float BLDCMotor::getSpeed() {
    return this->speed;
}

void BLDCMotor::stop() {
    this->setSpeed(0);
}

void BLDCMotor::setPwmDutyCycle(uint16_t duty_cycle) {
    pwm_set_chan_level(this->slice_num, this->channel, duty_cycle);
}