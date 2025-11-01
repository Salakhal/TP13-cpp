#ifndef ARRAYDYN_HPP
#define ARRAYDYN_HPP

#include <cstddef>
#include <stdexcept>
#include "Iterator.hpp"

template <typename T>
class ArrayDyn {
private:
    T* data;
    std::size_t capacity;
    std::size_t size;

public:
    using iterator = Iterator<T>;

   
    ArrayDyn() : data(nullptr), capacity(0), size(0) {}
    ArrayDyn(std::size_t cap) : data(new T[cap]), capacity(cap), size(0) {}
    ArrayDyn(const ArrayDyn& other) : data(new T[other.capacity]), capacity(other.capacity), size(other.size) {
        for (std::size_t i = 0; i < size; ++i) data[i] = other.data[i];
    }
    ~ArrayDyn() { delete[] data; }

    ArrayDyn& operator=(const ArrayDyn& other) {
        if (this != &other) {
            delete[] data;
            capacity = other.capacity;
            size = other.size;
            data = new T[capacity];
            for (std::size_t i = 0; i < size; ++i) data[i] = other.data[i];
        }
        return *this;
    }

    void push_back(const T& value) {
        if (size == capacity) {
            std::size_t newCap = (capacity == 0) ? 1 : capacity * 2;
            T* newData = new T[newCap];
            for (std::size_t i = 0; i < size; ++i) newData[i] = data[i];
            delete[] data;
            data = newData;
            capacity = newCap;
        }
        data[size++] = value;
    }

    void pop_back() { if (size == 0) throw std::out_of_range("ArrayDyn vide"); --size; }

    T& operator[](std::size_t index) { 
        if (index >= size) throw std::out_of_range("Index hors limites"); 
        return data[index]; 
    }
    const T& operator[](std::size_t index) const { 
        if (index >= size) throw std::out_of_range("Index hors limites"); 
        return data[index]; 
    }

    std::size_t getSize() const { return size; }
    std::size_t getCapacity() const { return capacity; }
    bool empty() const { return size == 0; }

    iterator begin() { return iterator(data); }
    iterator end() { return iterator(data + size); }
};

#endif
