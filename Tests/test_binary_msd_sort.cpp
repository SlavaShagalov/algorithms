#include <gtest/gtest.h>

#include "binary_msd_sort.hpp"

// TEST(BubbleSort, EmptyArray) {
//     const int size = 0;
//     int *arr = nullptr;
//
//     bubbleSort(arr, size);
//
//     EXPECT_EQ(arr, nullptr);
// }

TEST(BinaryQuickSort, Simple) {
  const ssize_t size = 3;
  uint64_t arr[size] = {4, 1000000, 7};

  binaryQuickSort(arr, size);

  const ssize_t clearResSize = 3;
  uint64_t clearRes[clearResSize] = {4, 7, 1000000};
  for (int i = 0; i < clearResSize; ++i) {
    EXPECT_EQ(clearRes[i], arr[i]);
  }
}

TEST(BinaryQuickSort, SomeRandomElements) {
  const ssize_t size = 5;
  uint64_t arr[size] = {13, 0, 0xFFFFFFFFFFFFFFFF, 11, 1};

  binaryQuickSort(arr, size);

  const ssize_t clearResSize = 5;
  uint64_t clearRes[clearResSize] = {0, 1, 11, 13, 0xFFFFFFFFFFFFFFFF};
  for (int i = 0; i < clearResSize; ++i) {
    EXPECT_EQ(clearRes[i], arr[i]);
  }
}

TEST(BinaryQuickSort, Ascending) {
  const ssize_t size = 15;
  uint64_t arr[size] = {11, 11,  11,  13,  20,  35,  36, 37,
                        37, 100, 120, 120, 123, 231, 435};

  binaryQuickSort(arr, size);

  const int clearResSize = 15;
  int clearRes[clearResSize] = {11, 11,  11,  13,  20,  35,  36, 37,
                                37, 100, 120, 120, 123, 231, 435};
  for (int i = 0; i < clearResSize; ++i) {
    EXPECT_EQ(clearRes[i], arr[i]);
  }
}

TEST(BinaryQuickSort, Descending) {
  const ssize_t size = 15;
  uint64_t arr[size] = {435, 231, 123, 120, 120, 100, 37, 37,
                        36,  35,  20,  13,  11,  11,  11};

  binaryQuickSort(arr, size);

  const int clearResSize = 15;
  int clearRes[clearResSize] = {11, 11,  11,  13,  20,  35,  36, 37,
                                37, 100, 120, 120, 123, 231, 435};
  for (int i = 0; i < clearResSize; ++i) {
    EXPECT_EQ(clearRes[i], arr[i]);
  }
}

TEST(BinaryQuickSort, OneElement) {
  const ssize_t size = 1;
  uint64_t arr[size] = {34};

  binaryQuickSort(arr, size);

  const int clearResSize = 1;
  int clearRes[clearResSize] = {34};
  EXPECT_EQ(clearRes[0], arr[0]);
}