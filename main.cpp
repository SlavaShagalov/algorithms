#include <iostream>

#include "algorithmsConfig.h"

#include "Sort/BubbleSort/bubble_sort.h"

int main(int argc, char* argv[]) {
    // printf("F10 = %d\n", fib(10));

    std::cout << argv[0] << " Version " << algorithms_VERSION_MAJOR << "."
              << algorithms_VERSION_MINOR << std::endl;

    const int SIZE = 5;
    int arr[SIZE] = {2, 5, 0, -4, 0};

    bubbleSort(arr, SIZE); 

    for (int i = 0; i < SIZE; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << std::endl; 
}