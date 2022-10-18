#ifndef QUEUE_USING_STACKS_HPP
#define QUEUE_USING_STACKS_HPP

#include <cstddef>
#include <cassert>

#include "stack.hpp"

template<typename T>
class QueueUsingStacks {
private:
    Stack<T> inStack;
    Stack<T> outStack;

public:
    QueueUsingStacks() : inStack(), outStack() {}

    explicit QueueUsingStacks(size_t size) {
        const size_t inSize = size / 2;
        inStack(inSize);
        outStack(size - inSize);
    }

    ~QueueUsingStacks() = default;

    // methods
    void push(const T &elem) { inStack.push(elem); }

    T pop();

    bool empty() const { return inStack.empty() && outStack.empty(); }
};

template<typename T>
T QueueUsingStacks<T>::pop() {
    if (!outStack.empty())
        return outStack.pop();

    while (!inStack.empty())
        outStack.push(inStack.pop());

    return outStack.pop();
}

#endif  // QUEUE_USING_STACKS_HPP
