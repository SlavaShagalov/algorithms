#ifndef COUNTING_SORT_HPP
#define COUNTING_SORT_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "string.h"

template <typename T>
void CountingSort1(int *arr, const size_t size) {
  static const size_t k = 8;

  size_t *c = new size_t[k];
  for (size_t i = 0; i < k; ++i) c[i] = 0;
  for (size_t i = 0; i < size; ++i) ++c[arr[i]];
  int pos = 0;
  for (size_t i = 0; i < k; ++i)
    for (size_t j = 0; j < c[i]; ++j) arr[pos++] = i;
  delete[] c;
}

template <typename T>
void CountingSort2(int *arr, const size_t size) {
  static const size_t k = 8;

  int *c = new int[k];
  for (size_t i = 0; i < k; ++i) c[i] = 0;
  for (size_t i = 0; i < size; ++i) ++c[arr[i]];
  int sum = 0;
  for (size_t i = 0; i < k; ++i) {
    int tmp = c[i];
    c[i] = sum;  // Начала групп.
    sum += tmp;
  }
  int *b = new int[size];
  for (size_t i = 0; i < size; ++i) {
    b[c[arr[i]]++] = arr[i];
  }
  delete[] c;
  memcpy(arr, b, size * sizeof(int));
  delete[] b;
}

#endif  // COUNTING_SORT_HPP
