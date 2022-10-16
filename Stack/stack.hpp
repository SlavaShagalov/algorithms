#ifndef STACK_HPP
#define STACK_HPP

#include <cstddef>

template<typename T>
class Stack {
private:
    static const size_t initSize = 8;

    T *_buffer;
    size_t _capacity;
    size_t _top;

    void resize();

public:
    Stack() : _buffer(nullptr), _capacity(0), _top(-1) {}

    explicit Stack(const size_t capacity) : _capacity(capacity), _top(-1) { _buffer = new T[_capacity]; }

    ~Stack() { delete[] _buffer; }

    // methods
    void push(const T &elem);

    T pop();

    bool empty() const { return _top == -1; }
};

template<typename T>
void Stack<T>::push(const T &elem) {
    if (_top + 1 >= _capacity)
        resize();
    assert(_top + 1 < _capacity && _buffer != nullptr);
    _buffer[++_top] = elem;
}

template<typename T>
T Stack<T>::pop() {
    assert(_top != -1);
    return _buffer[_top--];
}

template<typename T>
void Stack<T>::resize() {
    _capacity = std::max(_capacity * 2, initSize);
    T *newBuffer = new T[_capacity];
    std::copy(_buffer, _buffer + _top, newBuffer);
    delete[] _buffer;
    _buffer = newBuffer;
}

#endif // STACK_HPP