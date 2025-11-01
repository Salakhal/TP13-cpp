#ifndef STACK_HPP
#define STACK_HPP

#include <memory>
#include <stdexcept>
#include <cstddef>
#include <iterator>


class StackOverflow : public std::runtime_error {
public:
    StackOverflow() : std::runtime_error("Stack Overflow") {}
};

class StackUnderflow : public std::runtime_error {
public:
    StackUnderflow() : std::runtime_error("Stack Underflow") {}
};


template <typename T>
class Stack {
private:
    std::unique_ptr<T[]> data;
    std::size_t capacity;
    std::size_t topIndex; 
public:
    
    Stack(std::size_t cap = 10) : capacity(cap), topIndex(0) {
        data = std::make_unique<T[]>(capacity);
    }

    template <typename Iter>
    Stack(Iter begin, Iter end) {
        capacity = std::distance(begin, end);
        topIndex = 0;
        data = std::make_unique<T[]>(capacity);
        for (Iter it = begin; it != end; ++it)
            push(*it);
    }

  
    void push(const T& value) {
        if (topIndex >= capacity) throw StackOverflow();
        data[topIndex++] = value;
    }

    void pop() {
        if (empty()) throw StackUnderflow();
        --topIndex;
    }

    T& peek() const {
        if (empty()) throw StackUnderflow();
        return data[topIndex - 1];
    }

    bool empty() const { return topIndex == 0; }

    std::size_t size() const { return topIndex; }
};

#endif
