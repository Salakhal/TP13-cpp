#include "SortFunctor.hpp"
#include <vector>
#include <string>
#include <iostream>

struct Personne {
    std::string nom;
    int age;

    Personne(std::string n, int a) : nom(n), age(a) {}

    bool operator<(const Personne& other) const {
        return age < other.age;
    }

   
    bool operator>(const Personne& other) const {
        return age > other.age;
    }
};

template <typename T>
void printVector(const std::vector<T>& v) {
    for (auto& e : v) std::cout << e << " ";
    std::cout << std::endl;
}

template <>
void printVector(const std::vector<Personne>& v) {
    for (auto& p : v) std::cout << p.nom << "(" << p.age << ") ";
    std::cout << std::endl;
}

int main() {
    std::vector<int> v1{5,3,8,1,2};
    quickSort(v1, Asc{});
    std::cout << "Int Asc: ";
    printVector(v1);

    quickSort(v1, Desc{});
    std::cout << "Int Desc: ";
    printVector(v1);

    std::vector<std::string> v2{"Banana","Apple","Orange"};
    quickSort(v2, Asc{});
    std::cout << "String Asc: ";
    printVector(v2);

    quickSort(v2, Desc{});
    std::cout << "String Desc: ";
    printVector(v2);

    std::vector<Personne> v3{
        {"Salma",21},
        {"John",25},
        {"Alice",20}
    };

    quickSort(v3, Asc{});
    std::cout << "Personne Asc: ";
    printVector(v3);

    quickSort(v3, Desc{});
    std::cout << "Personne Desc: ";
    printVector(v3);

    return 0;
}
