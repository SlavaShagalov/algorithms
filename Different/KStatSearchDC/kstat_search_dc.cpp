#include "kstat_search_dc.hpp"

// Поиск K-ой порядковой статистики методом "Разделяй
// и властвуй"
//int kStatSearchDC(int* arr, const int size, const int k) {
//  int part = partition(arr, size);
//
//  if (part == k)
//    return part;
//  else if (part > k)
//    return kStatSearchDC(arr, part, k);
//  else
//    return kStatSearchDC(arr + part + 1, size - (part + 1), k - (part + 1));
//}
