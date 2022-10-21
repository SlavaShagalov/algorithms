#include <gtest/gtest.h>

#include "bit_operation.hpp"

TEST(GetBit, FirstBitZero) {
    uint32_t num = 26;
    uint8_t index = 0;

    bool value = getBit(num, index);

    EXPECT_EQ(value, 0);
}

TEST(GetBit, FirstBitOne) {
  uint32_t num = 25;
  uint8_t index = 0;

  bool value = getBit(num, index);

  EXPECT_EQ(value, 1);
}

TEST(GetBit, MiddleBitZero) {
  uint32_t num = 25;
  uint8_t index = 2;

  bool value = getBit(num, index);

  EXPECT_EQ(value, 0);
}

TEST(GetBit, MiddleBitOne) {
  uint32_t num = 25;
  uint8_t index = 4;

  bool value = getBit(num, index);

  EXPECT_EQ(value, 1);
}

TEST(GetBit, LastBitZero) {
  uint32_t num = 25;
  uint8_t index = 31;

  bool value = getBit(num, index);

  EXPECT_EQ(value, 0);
}

TEST(GetBit, LastBitOne) {
    uint32_t num = 0x80000000;
    uint8_t index = 31;

    bool value = getBit(num, index);

    EXPECT_EQ(value, 1);
}