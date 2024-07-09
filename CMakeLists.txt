cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(onboard-computer C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

# Set the custom board definition
set(PICO_BOARD waveshare_rp2040_zero)

pico_sdk_init()

add_executable(${PROJECT_NAME}
    main.cpp
    src/rgb_led.cpp
)

pico_generate_pio_header(${PROJECT_NAME} ${CMAKE_CURRENT_LIST_DIR}/src/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
pico_set_program_name(${PROJECT_NAME} "onboard-computer")
pico_set_program_version(${PROJECT_NAME} "0.1")

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
    hardware_pio
)

target_include_directories(${PROJECT_NAME} PRIVATE
    ${CMAKE_CURRENT_LIST_DIR}/include
)

pico_add_extra_outputs(${PROJECT_NAME})

# add_subdirectory(tests)

# hardware_i2c
# hardware_pwm
# hardware_spi
# hardware_adc
# hardware_dma
# hardware_timer
# hardware_uart
# hardware_watchdog
# hardware_clocks
# hardware_divider
# hardware_vreg
# hardware_irq
# hardware_flash
# hardware_pll
# hardware_rtc
# hardware_structs
# hardware_sync
# pico_multicore
# pico_runtime
# pico_unique_id
# pico_time
# pico_util
# pico_bootrom
# pico_boot_stage2
# pico_boot_stage3
# pico_printf
# pico_platform