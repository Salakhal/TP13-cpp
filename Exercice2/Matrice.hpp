#include <iostream>
#include <initializer_list>
#include <stdexcept>
using namespace std;


template <typename T, size_t N, size_t M>
class Matrice {
private:
    T data[N][M]; 

public:
    
    Matrice() {
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < M; ++j)
                data[i][j] = T(0);
    }

    
    Matrice(initializer_list<initializer_list<T>> init) {
        size_t i = 0;
        for (auto &row : init) {
            size_t j = 0;
            for (auto &val : row) {
                if (i < N && j < M)
                    data[i][j] = val;
                ++j;
            }
            ++i;
        }
    }

   
    T& operator()(size_t i, size_t j) {
        if (i >= N || j >= M)
            throw out_of_range("Index hors limites");
        return data[i][j];
    }

    const T& operator()(size_t i, size_t j) const {
        if (i >= N || j >= M)
            throw out_of_range("Index hors limites");
        return data[i][j];
    }

   

  
    Matrice<T, N, M> operator+(const Matrice<T, N, M>& other) const {
        Matrice<T, N, M> res;
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < M; ++j)
                res.data[i][j] = data[i][j] + other.data[i][j];
        return res;
    }

    Matrice<T, N, M> operator-(const Matrice<T, N, M>& other) const {
        Matrice<T, N, M> res;
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < M; ++j)
                res.data[i][j] = data[i][j] - other.data[i][j];
        return res;
    }

    template <size_t P>
    Matrice<T, N, P> operator*(const Matrice<T, M, P>& other) const {
        Matrice<T, N, P> res;
        for (size_t i = 0; i < N; ++i)
            for (size_t j = 0; j < P; ++j) {
                res(i, j) = T(0);
                for (size_t k = 0; k < M; ++k)
                    res(i, j) += data[i][k] * other(k, j);
            }
        return res;
    }

   
    friend ostream& operator<<(ostream& os, const Matrice<T, N, M>& mat) {
        for (size_t i = 0; i < N; ++i) {
            os << "[ ";
            for (size_t j = 0; j < M; ++j)
                os << mat.data[i][j] << " ";
            os << "]\n";
        }
        return os;
    }
};
