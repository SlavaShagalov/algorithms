#ifndef BINARY_MSD_SORT_HPP
#define BINARY_MSD_SORT_HPP

#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstddef>

bool getBit(uint64_t num, int index) { return (num >> index) & 1; }

ssize_t partition(uint64_t *arr, const ssize_t size, const int idx) {
  if (size <= 1)
    return 0;

  ssize_t i = 0, j = size - 1;
  while (i <= j) {
    for (; i < size && getBit(arr[i], idx) == 0; ++i) {
    }
    for (; j >= 0 && getBit(arr[j], idx) == 1; --j) {
    }

    if (i < j)
      std::swap(arr[i++], arr[j--]);
  }
  return i;
}

void _binaryQuickSort(uint64_t *arr, const ssize_t size, const int idx) {
  assert(size > 0);
  if (idx < 0)
    return;

  ssize_t part = partition(arr, size, idx);

  if (part > 1) {
    _binaryQuickSort(arr, part, idx - 1);
  }
  if (part < size - 1) {
    _binaryQuickSort(arr + part, size - part, idx - 1);
  }
}

void binaryQuickSort(uint64_t *arr, const ssize_t size) {
  _binaryQuickSort(arr, size, 63);
}

// int partition(uint16_t *arr, const int size, const uint16_t pivot) {
//   if (size <= 1) return 0;
//
//   int i = 0, j = size - 1;
//   while (i <= j) {
//     for (; i < size && arr[i] < pivot; ++i) {
//     }
//     for (; j >= 0 && arr[j] >= pivot; --j) {
//     }
//
//     if (i < j) std::swap(arr[i++], arr[j--]);
//   }
//   return i;
// }
//
// void binaryMSD(uint16_t *arr, const int size, const uint16_t pivot,
//                const uint16_t mask) {
//   assert(size > 0);
//   if (mask == 0) return;
//
//   int part = partition(arr, size, pivot);
//   std::cout << "pivot = " << std::bitset<64>(pivot) << std::endl;
//
//   if (part > 0) {
//     binaryMSD(arr, part, (pivot & (~mask)) | (mask >> 1), mask >> 1);
//   }
//   if (part + 1 < size)
//     binaryMSD(arr + part + 1, size - (part + 1), pivot + (pivot >> 1),
//               mask >> 1);
// }
//
// void sort(uint16_t *arr, const int size) {
//   const uint16_t initPivot = 0x8000;
//
//   binaryMSD(arr, size, initPivot, initPivot);
// }

#endif  // BINARY_MSD_SORT_HPP
