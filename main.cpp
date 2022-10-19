#include <iostream>

#include "bubble_sort.hpp"
#include "dynamic_array.hpp"
#include "heap.hpp"
#include "queue.hpp"
#include "priority_queue.hpp"
#include "queue_using_stacks.hpp"
#include "stack.hpp"

int main(int argc, char *argv[]) {
  (void)argc;
  (void)argv;

  const int SIZE = 5;
  int arr[SIZE] = {2, 5, 0, -4, 0};

  bubbleSort(arr, SIZE);

  for (int i = 0; i < SIZE; i++) {
    std::cout << arr[i] << " ";
  }

  std::cout << std::endl;
}
