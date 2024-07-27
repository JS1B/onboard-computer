add_library(pwm_helper_library STATIC
    pwm_helper.cpp
)

target_include_directories(pwm_helper_library PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
)

target_link_libraries(pwm_helper_library PUBLIC
    pico_stdlib
    hardware_pwm
)