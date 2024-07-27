add_library(led_library STATIC
    led_controller.cpp
    rgb_led/rgb_led.cpp
    on_off_led/on_off_led.cpp
)

add_subdirectory(rgb_led)
add_subdirectory(on_off_led)

target_include_directories(led_library PUBLIC
    ${CMAKE_CURRENT_LIST_DIR}
    ${CMAKE_CURRENT_LIST_DIR}/rgb_led
    ${CMAKE_CURRENT_LIST_DIR}/on_off_led
)

target_link_libraries(led_library PUBLIC
    pico_stdlib
    hardware_pio
)