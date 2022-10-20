#include "kstat_search_dc.hpp"

int partition(int* arr, int size) {
  if (size <= 1) return 0;

  const int& pivot = arr[size - 1];
  int i = 0, j = size - 2;
  while (i <= j) {
    for (; arr[i] < pivot; ++i) {
    }
    for (; j >= 0 && arr[j] >= pivot; --j) {
    }

    if (i < j) std::swap(arr[i++], arr[j--]);
  }
  std::swap(arr[i], arr[size - 1]);
  return i;
}

// Поиск K-ой порядковой статистики методом "Разделяй
// и властвуй"
int kStatSearchDC(int* arr, const int size, const int k) {
  int part = partition(arr, size);

  if (part == k)
    return part;
  else if (part > k)
    return kStatSearchDC(arr, part, k);
  else
    return kStatSearchDC(arr + part + 1, size - (part + 1), k - (part + 1));
}
