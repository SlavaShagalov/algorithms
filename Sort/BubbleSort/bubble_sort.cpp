#include "bubble_sort.hpp"

void bubbleSort(int arr[], const int size) {
  int buff;

  for (int i = 0; i < size - 1; i++) {
    for (int j = size - 1; j > i; j--) {
      if (arr[j] < arr[j - 1]) {
        buff = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = buff;
      }
    }
  }
}
