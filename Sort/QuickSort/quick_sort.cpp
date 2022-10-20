#include "quick_sort.hpp"

int partition(int *arr, int size) {
  if (size <= 1)
    return 0;

  const int &pivot = arr[size - 1];
  int i = 0, j = size - 2;
  while (i <= j) {
    for (; arr[i] < pivot; ++i) {
    }
    for (; j >= 0 && arr[j] >= pivot; --j) {
    }

    if (i < j)
      std::swap(arr[i++], arr[j--]);
  }
  std::swap(arr[i], arr[size - 1]);
  return i;
}

void quickSort(int *arr, const int size) {
  int part = partition(arr, size);
  if (part > 0)
    quickSort(arr, part);
  if (part + 1 < size)
    quickSort(arr + part + 1, size - (part + 1));
}
