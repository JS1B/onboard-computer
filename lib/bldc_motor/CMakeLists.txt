add_library(bldc_motor_library STATIC
    bldc_motor.cpp
)

target_include_directories(bldc_motor_library PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(bldc_motor_library PUBLIC
    pico_stdlib
    hardware_pwm
    hardware_clocks
    pwm_helper_library
)
