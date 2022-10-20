#include <gtest/gtest.h>

#include "bubble_sort.hpp"

// TEST(BubbleSort, EmptyArray) {
//     const int size = 0;
//     int *arr = nullptr;
//
//     bubbleSort(arr, size);
//
//     EXPECT_EQ(arr, nullptr);
// }

TEST(BubbleSort, SomeRandomElements) {
  const int size = 3;
  int arr[size] = {-13, 20, 11};

  bubbleSort(arr, size);

  EXPECT_EQ(arr[0], -13);
  EXPECT_EQ(arr[1], 11);
  EXPECT_EQ(arr[2], 20);
}