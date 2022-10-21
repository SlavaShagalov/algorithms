#include <gtest/gtest.h>

#include "intersection.hpp"

TEST(Intersection, Simple) {
    const int sizeA = 10;
    int arrA[sizeA] = {-23, -15, -4, -3, -2, -1, 0, 9, 10, 11};
    const int sizeB = 6;
    int arrB[sizeB] = {-40, -23, -15, 0, 34, 145};
    int res[sizeB];
    int resSize = 0;

    intersection(arrA, sizeA, arrB, sizeB, res, &resSize);

    int clearRes[] = {-23, -15, 0};
    int clearResSize = 3;
    EXPECT_EQ(resSize, clearResSize);
    for (int i = 0; i < clearResSize; ++i)
        EXPECT_EQ(clearRes[i], res[i]);
}

TEST(Intersection, EmptyRes) {
    const int sizeA = 10;
    int arrA[sizeA] = {-23, -15, -4, -3, -2, -1, 0, 9, 10, 11};
    const int sizeB = 6;
    int arrB[sizeB] = {-40, -24, -14, 1, 34, 145};
    int res[sizeB];
    int resSize = 0;

    intersection(arrA, sizeA, arrB, sizeB, res, &resSize);

    int clearResSize = 0;
    EXPECT_EQ(resSize, clearResSize);
}

TEST(Intersection, IdenticalArrays) {
    const int sizeA = 10;
    int arrA[sizeA] = {-23, -15, -4, -3, -2, -1, 0, 9, 10, 11};
    const int sizeB = 10;
    int arrB[sizeB] = {-23, -15, -4, -3, -2, -1, 0, 9, 10, 11};
    int res[sizeB];
    int resSize = 10;

    intersection(arrA, sizeA, arrB, sizeB, res, &resSize);

    int clearRes[] = {-23, -15, -4, -3, -2, -1, 0, 9, 10, 11};
    int clearResSize = 10;
    EXPECT_EQ(resSize, clearResSize);
    for (int i = 0; i < clearResSize; ++i)
        EXPECT_EQ(clearRes[i], res[i]);
}