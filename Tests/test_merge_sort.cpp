#include <gtest/gtest.h>

#include "merge_sort.hpp"

// TEST(BubbleSort, EmptyArray) {
//     const int size = 0;
//     int *arr = nullptr;
//
//     bubbleSort(arr, size);
//
//     EXPECT_EQ(arr, nullptr);
// }

TEST(MergeSort, SomeRandomElements) {
  const size_t size = 3;
  int arr[size] = {-13, 20, 11};

  mergeSort(arr, size);

  EXPECT_EQ(arr[0], -13);
  EXPECT_EQ(arr[1], 11);
  EXPECT_EQ(arr[2], 20);
}

TEST(MergeSort, Ascending) {
  const int size = 15;
  int arr[size] = {-231, -123, -120, -120, -13, 11,  11, 11,
                   20,   35,   36,   37,   37,  100, 435};

  mergeSort(arr, size);

  const int clearResSize = 15;
  int clearRes[clearResSize] = {-231, -123, -120, -120, -13, 11,  11, 11,
                                20,   35,   36,   37,   37,  100, 435};
  for (int i = 0; i < clearResSize; ++i) {
    EXPECT_EQ(clearRes[i], arr[i]);
  }
}

TEST(MergeSort, Descending) {
  const int size = 15;
  int arr[size] = {435, 100, 37,  37,   36,   35,   20,  11,
                   11,  11,  -13, -120, -120, -123, -231};

  mergeSort(arr, size);

  const int clearResSize = 15;
  int clearRes[clearResSize] = {-231, -123, -120, -120, -13, 11,  11, 11,
                                20,   35,   36,   37,   37,  100, 435};
  for (int i = 0; i < clearResSize; ++i) {
    EXPECT_EQ(clearRes[i], arr[i]);
  }
}

TEST(MergeSort, OneElement) {
  const int size = 1;
  int arr[size] = {34};

  mergeSort(arr, size);

  const int clearResSize = 1;
  int clearRes[clearResSize] = {34};
  EXPECT_EQ(clearRes[0], arr[0]);
}