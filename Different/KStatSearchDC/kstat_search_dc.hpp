#ifndef KSTAT_SEARCH_DC_HPP
#define KSTAT_SEARCH_DC_HPP

#include <algorithm>
#include <cstddef>

#include "types.h"

int partition(int* arr, int size);

int kStatSearchDC(int* arr, const int size, const int k);

template <typename T, typename Comparator = DefaultComparator<T>>
int kStatSearchNonRecursive(int* arr, const int size, const int k) {
  int part = partition(arr, size);

  if (part == k)
    return part;
  else if (part > k)
    return kStatSearchDC(arr, part, k);
  else
    return kStatSearchDC(arr + part + 1, size - (part + 1), k - (part + 1));
}

#endif  // KSTAT_SEARCH_DC_HPP
