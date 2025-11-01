#include <iostream>
#include <string>
#include "ArrayDyn.hpp"


class Point {
private:
    int x, y;
public:
    Point(int a=0, int b=0) : x(a), y(b) {}
    friend std::ostream& operator<<(std::ostream& os, const Point& p) {
        os << "(" << p.x << "," << p.y << ")";
        return os;
    }
};

int main() {
   
    ArrayDyn<int> arrInt;
    arrInt.push_back(10);
    arrInt.push_back(20);
    arrInt.push_back(30);

    std::cout << "Array int: ";
    for (auto& val : arrInt) std::cout << val << " ";
    std::cout << std::endl;

  
    ArrayDyn<std::string> arrStr;
    arrStr.push_back("Bonjour");
    arrStr.push_back("C++");
    arrStr.push_back("Monde");

    std::cout << "Array string: ";
    for (auto& val : arrStr) std::cout << val << " ";
    std::cout << std::endl;

    
    ArrayDyn<Point> arrPts;
    arrPts.push_back(Point(1,2));
    arrPts.push_back(Point(3,4));

    std::cout << "Array Point: ";
    for (auto& p : arrPts) std::cout << p << " ";
    std::cout << std::endl;

    return 0;
}
