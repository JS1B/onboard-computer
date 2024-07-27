#include "pwm_helper.h"

#include <math.h>
#include "hardware/pwm.h"

pwm_clock_params pwm_determine_params(uint32_t freq, uint32_t clk_sys, round_mode mode) {
    pwm_clock_params params;

    params.target_freq = freq;
    params.wrap = UINT16_MAX;
    params.clock_div = 0;
    params.clock = clk_sys;

    uint32_t min_freq = params.clock / (UINT16_MAX * UINT8_MAX);
    if (freq <= min_freq) {
        params.clock_div = UINT8_MAX;
        params.actual_freq = min_freq;
        return params;
    }
    // else if (freq >= clock / 2) {
    //     wrap = 1;
    //     clock_div = 1;
    // }

    params.clock_div = ceil((float)params.clock / (params.wrap * freq));
    float w = params.clock / (freq * params.clock_div);

    switch (mode) {
    case round_mode::round_up:
        params.wrap = ceil(w);
        break;
    case round_mode::round_down:
        params.wrap = floor(w);
        break;
    case round_mode::round_to_nearest:
    default:
        params.wrap = round(w);
        break;
    }

    params.actual_freq = params.clock / (params.wrap * params.clock_div);
    return params;
}