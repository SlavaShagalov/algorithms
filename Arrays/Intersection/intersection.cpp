#include "intersection.hpp"

void intersection(const int *arrA, const int nArrA, const int *arrB,
                  const int nArrB, int *res, int *l) {
  int left = 0, right = 0, mid = 0;
  int value = 0;
  *l = 0;
  for (int i = 0; i < nArrB; i++) {
    value = arrB[i];

    // find range
    for (right = left + 1; right < nArrA && arrA[right] < value; right *= 2) {
    }
    left = right / 2;
    if (right > nArrA - 1) right = nArrA - 1;

    //        std::cout << left << "; " << right << std::endl;

    // binary search
    while (left < right) {
      mid = (left + right) / 2;
      if (arrA[mid] < value)
        left = mid + 1;
      else if (arrA[mid] >= value)
        right = mid;
    }
    if (arrA[left] == value) {
      res[(*l)++] = value;
    }
    if (left == nArrA - 1) break;
  }
}
