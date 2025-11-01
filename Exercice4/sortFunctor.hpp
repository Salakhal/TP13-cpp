#ifndef SORTFUNCTOR_HPP
#define SORTFUNCTOR_HPP

#include <vector>
#include <concepts>
#include <functional>
#include <string>
#include <iostream>

template<typename T>
concept Sortable = requires(T a, T b) {
    { a < b } -> std::convertible_to<bool>;
};


struct Asc {
    template <Sortable T>
    bool operator()(const T& a, const T& b) const {
        return a < b;
    }
};

struct Desc {
    template <Sortable T>
    bool operator()(const T& a, const T& b) const {
       
        return b < a;
    }
};


template <Sortable T, typename Comp = Asc>
void quickSort(std::vector<T>& vec, Comp comp = Comp{}) {
    if (vec.size() <= 1) return;

    auto partition = [&](int low, int high) {
        T pivot = vec[high];
        int i = low - 1;
        for (int j = low; j < high; ++j) {
            if (comp(vec[j], pivot)) {
                ++i;
                std::swap(vec[i], vec[j]);
            }
        }
        std::swap(vec[i + 1], vec[high]);
        return i + 1;
    };

    std::function<void(int,int)> qs = [&](int low, int high){
        if (low < high) {
            int pi = partition(low, high);
            qs(low, pi -1);
            qs(pi +1, high);
        }
    };

    qs(0, vec.size() -1);
}

#endif
