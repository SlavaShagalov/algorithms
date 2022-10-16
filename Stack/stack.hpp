#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef>

template<typename T>
class Stack {
private:
    T *_buffer;
    size_t _size;
    size_t _top;

public:
    explicit Stack(size_t size) : _size(size), _top(-1) { _buffer = new T[_size]; }

    ~Stack() { delete[] _buffer }

    // methods
    void push(const T &elem);

    T pop();

    bool empty() const { return _top == -1; }
};

template<typename T>
void Stack<T>::push(const T &elem) {
    assert(_top + 1 < _size);
    _buffer[++_top] = elem;
}

template<typename T>
T Stack<T>::pop() {
    assert(_top != -1);
    return _buffer[_top--];
}

#endif // STACK_HPP