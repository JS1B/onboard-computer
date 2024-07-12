file(MAKE_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR}/generated)
pico_generate_pio_header(led_library ${CMAKE_CURRENT_LIST_DIR}/ws2812.pio OUTPUT_DIR ${CMAKE_CURRENT_BINARY_DIR}/generated)
