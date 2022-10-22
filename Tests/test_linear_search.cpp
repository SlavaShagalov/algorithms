#include <gtest/gtest.h>

#include "linear_search.hpp"

TEST(LinearSearch, OneElemNotFound) {
    int arr[] = {4};
    int size = 1;
    int value = 5;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(LinearSearch, OneElemFound) {
    int arr[] = {5};
    int size = 1;
    int value = 5;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, 0);
}

TEST(LinearSearch, OddSizeFound) {
    int arr[9] = {-23, -4, -1, 0, 3, 5, 9, 10, 11};
    int size = 9;
    int value = 10;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, 7);
}

TEST(LinearSearch, OddSizeNotFound) {
    int arr[9] = {-23, -4, -1, 0, 3, 5, 9, 10, 11};
    int size = 9;
    int value = 2;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(LinearSearch, EvenSizeNotFound) {
    int arr[10] = {-23, -4, -1, 0, 3, 5, 9, 10, 11, 16};
    int size = 10;
    int value = -5;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(LinearSearch, EvenSizeFound) {
    int arr[10] = {-23, -4, -1, 0, 3, 5, 9, 10, 11, 16};
    int size = 10;
    int value = -4;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, 1);
}

TEST(LinearSearch, FirstOccurrence) {
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};
    int size = 10;
    int value = -4;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, 2);
}

TEST(LinearSearch, ValueMoreThanLastElem) {
    int size = 10;
    int value = 15;
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};

    int index = linearSearch(arr, size, value);
    EXPECT_EQ(index, -1);
}

TEST(LinearSearch, ValueLessThanFirstElem) {
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};
    int size = 10;
    int value = -24;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, -1);
}

TEST(LinearSearch, FirstElemFound) {
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};
    int size = 10;
    int value = -23;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, 0);
}

TEST(LinearSearch, LastElemFound) {
    int arr[10] = {-23, -15, -4, -4, -4, -1, 0, 9, 10, 11};
    int size = 10;
    int value = 11;

    int index = linearSearch(arr, size, value);

    EXPECT_EQ(index, 9);
}