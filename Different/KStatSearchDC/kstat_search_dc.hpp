#ifndef KSTAT_SEARCH_DC_HPP
#define KSTAT_SEARCH_DC_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>
#include <cstdlib>
#include <random>

#include "types.h"

// int partition(int *arr, int size) {
//   if (size <= 1)
//     return 0;
//
//   const int &pivot = arr[size - 1];
//   int i = 0, j = size - 2;
//   while (i <= j) {
//     for (; arr[i] < pivot; ++i) {
//     }
//     for (; j >= 0 && arr[j] >= pivot; --j) {
//     }
//
//     if (i < j)
//       std::swap(arr[i++], arr[j--]);
//   }
//   std::swap(arr[i], arr[size - 1]);
//   return i;
// }

// template <typename T, typename Comparator = DefaultComparator<T>>
// ssize_t partition(T *arr, const ssize_t l, const ssize_t r,
//                   Comparator comp = Comparator()) {
//   if ((r - l) <= 1)
//     return l;
//
//   std::default_random_engine defEngine;
//   std::uniform_int_distribution<ssize_t> intDistro(l,
//                                                    r - 1);  // random [l,
//                                                    r-1]
//
//   std::swap(arr[intDistro(defEngine)], arr[r - 1]);
//   const T &pivot = arr[r - 1];
//
//   ssize_t i = l;
//   for (ssize_t j = l; j < r; j++) {
//     if (!comp(arr[j], pivot)) {
//       std::swap(arr[i++], arr[j]);
//     }
//   }
//
//   return i - 1;
// }

template <typename T, typename Comparator = DefaultComparator<T>>
ssize_t partition(T *arr, const ssize_t l, const ssize_t r,
                  Comparator comp = Comparator()) {
  if ((r - l) <= 1)
    return l;

  std::default_random_engine defEngine;
  std::uniform_int_distribution<ssize_t> intDistro(l,
                                                   r - 1);  // random [l, r-1]

  std::swap(arr[intDistro(defEngine)], arr[r - 1]);
  const T &pivot = arr[r - 1];

  ssize_t i = r - 2;
  for (ssize_t j = r - 2; j >= 0; --j) {
    if (comp(arr[j], pivot)) {
      std::swap(arr[i--], arr[j]);
    }
  }
  std::swap(arr[i + 1], arr[r - 1]);

  return i + 1;
}

// int kStatSearchDC(int* arr, const int size, const int k);

// template <typename T, typename Comparator = DefaultComparator<T>>
// T kStatSearchRecursive(T *arr, const ssize_t size, const ssize_t k,
//                           Comparator comp = Comparator()) {
//   ssize_t part = partition(arr, size, comp);
//
//   if (part == k)
//     return arr[part];
//   else if (part > k)
//     return kStatSearchNonRecursive(arr, part, k);
//   else
//     return kStatSearchNonRecursive(arr + part + 1, size - (part + 1),
//                                    k - (part + 1));
// }

template <typename T, typename Comparator = DefaultComparator<T>>
T kStatSearch(const T *arr, const ssize_t size, const ssize_t k,
              Comparator comp = Comparator()) {
  assert(size > 0);
  assert(k >= 0 && k < size);

  T *tmp = new T[size];
  std::copy(arr, arr + size, tmp);

  ssize_t l = 0, r = size, m = 0;
  while (l < r) {
    m = partition(tmp, l, r, comp);
    if (m == k) {
      break;
    } else if (m < k) {
      l = m + 1;
    } else {
      r = m;
    }
  }

  T value = tmp[k];
  delete[] tmp;
  return value;
}

#endif  // KSTAT_SEARCH_DC_HPP
