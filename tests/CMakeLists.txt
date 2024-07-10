cmake_minimum_required(VERSION 3.13)

# Set the project name
project(onboard-computer-tests C CXX)

# Include directories
include_directories(${CMAKE_CURRENT_LIST_DIR}/../include)
include_directories(${CMAKE_CURRENT_BINARY_DIR}/../generated)

enable_testing()
find_package(GTest REQUIRED)

# Add the test executable
add_executable(tests
    test_rgb_led.cpp
    ../src/rgb_led.cpp
)

# Find Google Test
FindGTest()
include_directories(${GTEST_INCLUDE_DIRS})

# Link Google Test and pthread
target_link_libraries(tests ${GTEST_LIBRARIES} GTest::gtest GTest::gtest_main)

# Link the Pico SDK libraries
target_link_libraries(tests
    pico_stdlib
    hardware_pio
)