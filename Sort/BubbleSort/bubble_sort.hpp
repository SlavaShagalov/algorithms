#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

#include <algorithm>
#include <cassert>
#include <cstddef>

template <typename T>
struct DefaultComparator {
  bool operator()(const T &l, const T &r) const { return l < r; }
};

template <typename T, typename Comparator = DefaultComparator<T>>
void bubbleSort(T *arr, const size_t size, Comparator comp = Comparator()) {
  assert(size > 0);
  for (size_t i = 0; i < size - 1; i++)
    for (size_t j = size - 1; j > i; j--)
      if (comp(arr[j], arr[j - 1])) std::swap(arr[j], arr[j - 1]);

  int *p = new int;
  *p = 5;
}

#endif  // BUBBLE_SORT_H
