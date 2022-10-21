#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "../../types.h"

template <typename T, typename Comparator = DefaultComparator<T>>
void bubbleSort(T *arr, const size_t size, Comparator comp = Comparator()) {
  assert(size > 0);
  for (size_t i = 0; i < size - 1; i++) {
    for (size_t j = size - 1; j > i; j--) {
      if (comp(arr[j - 1], arr[j])) {
        std::swap(arr[j], arr[j - 1]);
      }
    }
  }
}

#endif  // BUBBLE_SORT_H
