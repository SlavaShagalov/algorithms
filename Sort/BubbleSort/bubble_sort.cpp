#include "bubble_sort.h"

void bubbleSort(int arr[], const size_t size)
{
    int buff;
 
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = size - 1; j > i; j--) 
        {
            if (arr[j] < arr[j - 1])
            {
                buff = arr[j - 1];
                arr[j - 1] = arr[j];
                arr[j] = buff;
            }
        }
    }
}