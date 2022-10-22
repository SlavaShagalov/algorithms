#include <gtest/gtest.h>

#include "kstat_search_dc.hpp"

TEST(KStatSearch, OneElement) {
  const ssize_t size = 1;
  const int arr[size] = {9};
  const ssize_t k = 0;

  const int value = kStatSearchNonRecursive(arr, size, k);

  EXPECT_EQ(value, 9);
}

TEST(KStatSearch, TwoElements) {
  const ssize_t size = 2;
  const int arr[size] = {9, 2};
  const ssize_t k = 1;

  const int value = kStatSearchNonRecursive(arr, size, k);

  EXPECT_EQ(value, 9);
}

TEST(KStatSearch, FirstElement) {
  const ssize_t size = 10;
  const int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const ssize_t k = 0;

  const int value = kStatSearchNonRecursive(arr, size, k);

  EXPECT_EQ(value, 1);
}

TEST(KStatSearch, Persent10) {
  const ssize_t size = 10;
  const int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const ssize_t k = 1;

  const int value = kStatSearchNonRecursive(arr, size, k);

  EXPECT_EQ(value, 2);
}

TEST(KStatSearch, PersentMedianEvenSize) {
  const ssize_t size = 10;
  const int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const ssize_t k = 5;

  const int value = kStatSearchNonRecursive(arr, size, k);

  EXPECT_EQ(value, 6);
}

TEST(KStatSearch, PersentMedianOddSize) {
  const ssize_t size = 11;
  const int arr[size] = {11, 2, 8, 4, 1, 6, 7, 3, 9, 10, 5};
  const ssize_t k = 5;

  const int value = kStatSearchNonRecursive(arr, size, k);

  EXPECT_EQ(value, 6);
}

TEST(KStatSearch, Persent90) {
  const ssize_t size = 10;
  const int arr[size] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  const ssize_t k = 9;

  const int value = kStatSearchNonRecursive(arr, size, k);

  EXPECT_EQ(value, 10);
}