#ifndef PRIORITY_QUEUE_HPP
#define PRIORITY_QUEUE_HPP

#include <cassert>
#include <cstddef>

template <typename T>
class PriorityQueue {
 private:
  Heap<T> _heap;

 public:
  explicit PriorityQueue(size_t size) : _heap(size) {}

  ~PriorityQueue() = default;

  // methods
  void push(const T &elem, void (*comparator)());
  T pop();
  T top() const;
};

// template <typename T>
// T PriorityQueue<T>::pop() {
//   assert(_head != _tail);
//   T result = _buffer[_head];
//   _head = (_head + 1) % _size;
//   return result;
// }
template <typename T>
T PriorityQueue<T>::top() const {
  return nullptr;
}
template <typename T>
void PriorityQueue<T>::push(const T &elem, void (*comparator)()) {}

#endif  // PRIORITY_QUEUE_HPP
