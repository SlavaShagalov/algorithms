#include "binary_search.hpp"

int binarySearch(const int *arr, const int n, const int value) {
    int left = 0, right = n - 1, mid = 0;

    while (left < right) {
        mid = (left + right) >> 1;
        if (arr[mid] < value)
            left = mid + 1;
        else if (arr[mid] >= value)
            right = mid;
    }

    return arr[left] == value ? left : -1;
}