#include "linear_search.hpp"

int linearSearch(const int *arr, const int n, const int value) {
  for (int i = 0; i < n; i++)
    if (arr[i] == value)
      return i;
  return -1;
}
