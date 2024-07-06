cmake_minimum_required(VERSION 3.13)

include($ENV{PICO_SDK_PATH}/external/pico_sdk_import.cmake)

project(onboard-computer C CXX ASM)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 17)

pico_sdk_init()

add_executable(${PROJECT_NAME}
    main.c    
)

pico_add_extra_outputs(${PROJECT_NAME})

target_link_libraries(${PROJECT_NAME}
    pico_stdlib
)

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

pico_enable_stdio_usb(${PROJECT_NAME} 1)
pico_enable_stdio_uart(${PROJECT_NAME} 0)