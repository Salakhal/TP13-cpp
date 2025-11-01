#ifndef ITERATOR_HPP
#define ITERATOR_HPP

template <typename T>
class Iterator {
private:
    T* ptr;

public:
    Iterator(T* p = nullptr) : ptr(p) {}

    
    T& operator*() const { return *ptr; }

    
    Iterator& operator++() { ++ptr; return *this; }
    Iterator& operator--() { --ptr; return *this; }

    Iterator operator++(int) { Iterator tmp(*this); ++(*this); return tmp; }
    Iterator operator--(int) { Iterator tmp(*this); --(*this); return tmp; }

    bool operator!=(const Iterator& other) const { return ptr != other.ptr; }
};

#endif
