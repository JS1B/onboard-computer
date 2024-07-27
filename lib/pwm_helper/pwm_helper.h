#ifndef PWM_HELPER_H
#define PWM_HELPER_H

#include "pico/stdlib.h"

typedef struct pwm_clock_params {
    uint32_t clock;
    uint16_t wrap;
    uint8_t clock_div;

    uint32_t target_freq;
    uint32_t actual_freq;
} pwm_clock_params;

typedef enum {
    round_up,
    round_down,
    round_to_nearest
} round_mode;

/**
 * @brief Get frequency parameters for PWM
 * @param[in] freq      The required frequency to be set
 * @param[in] clk_sys   The system clock frequency
 * @param[in] mode      The rounding mode
 *
 * @return pwm_clock_params struct with the actual frequency, clock, wrap and clock_div
 */
pwm_clock_params pwm_determine_params(uint32_t freq, uint32_t clk_sys, round_mode mode = round_to_nearest);

#endif // PWM_HELPER_H