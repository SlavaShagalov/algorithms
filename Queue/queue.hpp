#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <cstddef>
#include <cassert>

template<typename T>
class Queue {
private:
    T *_buffer;
    size_t _size;
    size_t _head;
    size_t _tail;

public:
    explicit Queue(size_t size) : _size(size), _head(0), _tail(0) { _buffer = new T[_size]; }

    ~Queue() { delete[] _buffer; }

    // methods
    void push(const T &elem);

    T pop();

    bool empty() const { return _head == _tail; }
};

template<typename T>
void Queue<T>::push(const T &elem) {
    assert((_tail + 1) % _size != _head);
    _buffer[_tail] = elem;
    _tail = (_tail + 1) % _size;
}

template<typename T>
T Queue<T>::pop() {
    assert(_head != _tail);
    T result = _buffer[_head];
    _head = (_head + 1) % _size;
    return result;
}

#endif  // QUEUE_HPP
