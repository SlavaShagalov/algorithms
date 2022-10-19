#ifndef HEAP_HPP
#define HEAP_HPP

#include <algorithm>
#include <cassert>
#include <cstddef>

#include "dynamic_array.hpp"

template <typename T>
using Array = DynamicArray<T>;

template <typename T>
class Heap {
 private:
  Array<T> _arr;

  void buildHeap();
  void siftDown(int i);
  void siftUp(int i);

 public:
  Heap() : _arr() {}
  Heap(const Heap<T> &other) = default;
  Heap(Heap<T> &&other) noexcept : _arr(std::move(other._arr)) {}

  explicit Heap(size_t capacity) : _arr(capacity) {}

  ~Heap() = default;

  // methods
  void insert(const T &elem);
  T extractMax();
  T peekMax() const {}
};

template <typename T>
void Heap<T>::siftDown(int i) {
  int left = 2 * i + 1;
  int right = 2 * i + 2;

  int largest = i;
  if (left < _arr.size() && _arr[left] > _arr[i]) largest = left;
  if (right < _arr.size() && _arr[right] > _arr[largest]) largest = right;

  if (largest != i) {
    std::swap(_arr[i], _arr[largest]);
    siftDown(largest);
  }
}

template <typename T>
void Heap<T>::buildHeap() {
  for (int i = _arr.size() / 2 - 1; i >= 0; --i) siftDown(i);
}

template <typename T>
void Heap<T>::siftUp(int i) {
  while (i > 0) {
    int parent = (i - 1) / 2;
    if (_arr[i] <= _arr[parent]) return;
    std::swap(_arr[i], _arr[parent]);
    i = parent;
  }
}

template <typename T>
void Heap<T>::insert(const T &elem) {
  _arr.add(elem);
  siftUp(_arr.size() - 1);
}

template <typename T>
T Heap<T>::extractMax() {
  assert(!_arr.empty());
  int result = _arr[0];
  _arr[0] = _arr.last();
  _arr.deleteLast();
  if (!_arr.empty()) siftDown(0);
  return result;
}

#endif  // HEAP_HPP
