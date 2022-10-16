#include <gtest/gtest.h>

#include "bit_operation.hpp"

TEST(GetBit, Bit0) {
    uint32_t num = 25;
    uint8_t index = 2;

    bool value = getBit(num, index);

    EXPECT_EQ(value, 0);
}

TEST(GetBit, Bit1) {
    uint32_t num = 25;
    uint8_t index = 3;

    bool value = getBit(num, index);

    EXPECT_EQ(value, 1);
}