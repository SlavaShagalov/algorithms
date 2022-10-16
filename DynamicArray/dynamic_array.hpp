#ifndef DYNAMIC_ARRAY_HPP
#define DYNAMIC_ARRAY_HPP

#include <cstddef>
#include <cassert>

template<typename T>
class DynamicArray {
private:
    static const size_t initSize = 8;

    T *_buffer;
    size_t _size{};
    size_t _capacity{};

    void resize();

public:
    DynamicArray() : _buffer(nullptr), _size(0), _capacity(0) {}

    DynamicArray(const DynamicArray &other);

    DynamicArray(DynamicArray &&other) noexcept;

    explicit DynamicArray(size_t capacity);

    ~DynamicArray() { delete[] _buffer; }

    // operators
    T operator[](size_t index) const;

    T &operator[](size_t index);

    // methods
    size_t size() const { return _size; }

    void add(const T &elem);
};


template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &other) : _size(other._size), _capacity(_size) {
    _buffer = new T[_capacity];
    std::copy(other._buffer, other._buffer + other._size, _buffer);
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray &&other) noexcept {
    _size = other._size;
    _capacity = other._capacity;
    _buffer = other._buffer;
    other._buffer = nullptr;
    other._size = other._capacity = 0;
}

template<typename T>
void DynamicArray<T>::resize() {
    _capacity = std::max(_capacity * 2, initSize);
    T *newBuffer = new T[_capacity];
    std::copy(_buffer, _buffer + _size, newBuffer);
    delete[] _buffer;
    _buffer = newBuffer;
}

template<typename T>
T DynamicArray<T>::operator[](size_t index) const {
    assert(index >= 0 && index < _size && _buffer != nullptr);
    return _buffer[index];
}

template<typename T>
T &DynamicArray<T>::operator[](size_t index) {
    assert(index >= 0 && index < _size && _buffer != nullptr);
    return _buffer[index];
}

template<typename T>
void DynamicArray<T>::add(const T &elem) {
    if (_size == _capacity)
        resize();
    assert(_size < _capacity && _buffer != nullptr);
    _buffer[_size++] = elem;
}

template<typename T>
DynamicArray<T>::DynamicArray(const size_t capacity) : _size(0), _capacity(capacity)  {
    _buffer = new T[_capacity];
}

#endif // DYNAMIC_ARRAY_HPP