#include <iostream>

#include "binary_search.hpp"
#include "bubble_sort.hpp"
#include "dynamic_array.hpp"
#include "heap.hpp"
#include "merge_sort.hpp"
#include "priority_queue.hpp"
#include "queue.hpp"
#include "queue_using_stacks.hpp"
#include "stack.hpp"
#include "binary_msd_sort.hpp"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  const int size = 5;
  int arr[size] = {2, 5, 0, -4, 0};

  bubbleSort(arr, size);

  for (int i = 0; i < size; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
}
