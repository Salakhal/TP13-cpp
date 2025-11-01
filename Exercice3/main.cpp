#include "Stack.hpp"
#include <iostream>
#include <vector>

int main() {
    try {
        Stack<int> s(5); 

        std::cout << "Empilage des nombres 1 à 5...\n";
        for (int i = 1; i <= 5; ++i) {
            s.push(i);
            std::cout << "push(" << i << ")\n";
        }

       
        try {
            s.push(6);
        } catch (const StackOverflow& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        
        std::cout << "Sommet: " << s.peek() << std::endl;

        
        std::cout << "Dépilement...\n";
        while (!s.empty()) {
            std::cout << s.peek() << " ";
            s.pop();
        }
        std::cout << std::endl;

        
        try {
            s.pop();
        } catch (const StackUnderflow& e) {
            std::cout << "Exception: " << e.what() << std::endl;
        }

        std::vector<int> v = {10,20,30};
        Stack<int> s2(v.begin(), v.end());
        std::cout << "Stack initialisée à partir d'un vector: ";
        while (!s2.empty()) {
            std::cout << s2.peek() << " ";
            s2.pop();
        }
        std::cout << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Erreur: " << e.what() << std::endl;
    }

    return 0;
}
