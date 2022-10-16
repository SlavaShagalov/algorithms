#include <gtest/gtest.h>

#include "binary_search.hpp"

TEST(BinarySearch, Empty) {
    int arr[] = {};
    int size = 0;
    int value = 5;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(BinarySearch, OneElemNotFound) {
    int arr[] = {4};
    int size = 1;
    int value = 5;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(BinarySearch, OneElemFound) {
    int arr[] = {5};
    int size = 1;
    int value = 5;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, 0);
}

TEST(BinarySearch, OddSizeFound) {
    int arr[9] = {-23, -4, -1, 0, 3, 5, 9, 10, 11};
    int size = 9;
    int value = 10;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, 7);
}

TEST(BinarySearch, OddSizeNotFound) {
    int arr[9] = {-23, -4, -1, 0, 3, 5, 9, 10, 11};
    int size = 9;
    int value = 2;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(BinarySearch, EvenSizeNotFound) {
    int arr[10] = {-23, -4, -1, 0, 3, 5, 9, 10, 11, 16};
    int size = 10;
    int value = -5;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(BinarySearch, EvenSizeFound) {
    int arr[10] = {-23, -4, -1, 0, 3, 5, 9, 10, 11, 16};
    int size = 10;
    int value = -4;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, 1);
}

TEST(BinarySearch, FirstOccurrence) {
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};
    int size = 10;
    int value = -4;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, 2);
}

TEST(BinarySearch, ValueMoreThanLastElem) {
    int size = 10;
    int value = 15;
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};

    int index = binarySearch(arr, size, value);
    EXPECT_EQ(index, -1);
}

TEST(BinarySearch, ValueLessThanFirstElem) {
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};
    int size = 10;
    int value = -24;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(BinarySearch, FirstElemFound) {
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};
    int size = 10;
    int value = -23;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, 0);
}

TEST(BinarySearch, LastElemFound) {
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};
    int size = 10;
    int value = 11;

    int index = binarySearch(arr, size, value);

    EXPECT_EQ(index, 9);
}