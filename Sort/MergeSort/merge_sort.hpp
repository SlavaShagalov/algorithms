#ifndef MERGE_SORT_HPP
#define MERGE_SORT_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "types.h"

template <typename T, typename Comparator = DefaultComparator<T>>
void merge(const T *arr1, const size_t n1, const T *arr2, const size_t n2,
           T *dest, Comparator comp = Comparator()) {
  size_t i = 0, j = 0, k = 0;
  while (i < n1 && j < n2) {
    if (comp(arr1[i], arr2[j])) {
      dest[k++] = arr2[j++];
    } else {
      dest[k++] = arr1[i++];
    }
  }

  for (; i < n1; ++i) {
    dest[k++] = arr1[i];
  }
  for (; j < n2; ++j) {
    dest[k++] = arr2[j];
  }
}

template <typename T, typename Comparator = DefaultComparator<T>>
void mergeSort(T *arr, const size_t size, Comparator comp = Comparator()) {
  if (size <= 1) {
    return;
  }

  size_t firstSize = size / 2;
  size_t secondSize = size - firstSize;
  mergeSort(arr, firstSize);
  mergeSort(arr + firstSize, secondSize);
  T *tmp = new T[size];
  merge(arr, firstSize, arr + firstSize, secondSize, tmp, comp);
  std::copy(tmp, tmp + size, arr);
  delete[] tmp;
}

#endif  // MERGE_SORT_HPP
