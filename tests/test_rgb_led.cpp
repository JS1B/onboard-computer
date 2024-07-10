#include <gtest/gtest.h>
#include "rgb_led.h"

class RGBLEDTest : public ::testing::Test {
protected:
    PIO pio;
    int sm;
    RGBLED* led;

    void SetUp() override {
        pio = pio0;
        sm = 0;
        led = new RGBLED(pio, sm, PICO_DEFAULT_WS2812_PIN, 800000);
    }

    void TearDown() override {
        delete led;
    }
};

TEST_F(RGBLEDTest, InitialState) {
    ASSERT_EQ(led->getRed(), 0);
    ASSERT_EQ(led->getGreen(), 0);
    ASSERT_EQ(led->getBlue(), 0);
    ASSERT_EQ(led->getBrightness(), 255);
}

TEST_F(RGBLEDTest, SetColor) {
    led->setColor(255, 128, 64);
    led->apply();
    ASSERT_EQ(led->getRed(), 255);
    ASSERT_EQ(led->getGreen(), 128);
    ASSERT_EQ(led->getBlue(), 64);
}

TEST_F(RGBLEDTest, SetBrightness) {
    led->setBrightness(128);
    led->apply();
    ASSERT_EQ(led->getBrightness(), 128);
}

TEST_F(RGBLEDTest, ApplyColor) {
    led->setColor(255, 0, 0);
    led->setBrightness(128);
    led->apply();
    // You may need a way to verify the actual output on the LED, which might involve mocking the PIO functions
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}