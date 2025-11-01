#include <iostream>
#include "Matrice.hpp"
using namespace std;

int main() {
    Matrice<int, 2, 2> A{{1, 2}, {3, 4}};
    Matrice<int, 2, 2> B{{5, 6}, {7, 8}};

    cout << "Matrice A :\n" << A;
    cout << "Matrice B :\n" << B;

    cout << "A + B :\n" << (A + B);
    cout << "A - B :\n" << (A - B);

    Matrice<int, 2, 3> C{{1, 2, 3}, {4, 5, 6}};
    Matrice<int, 3, 2> D{{7, 8}, {9, 10}, {11, 12}};
    cout << "C * D :\n" << (C * D);

    Matrice<double, 2, 2> E{{1.5, 2.5}, {3.5, 4.5}};
    Matrice<double, 2, 2> F{{0.5, 1.5}, {2.5, 3.5}};
    cout << "E + F :\n" << (E + F);

    return 0;
}
