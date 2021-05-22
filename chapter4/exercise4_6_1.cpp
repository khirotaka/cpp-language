#include <iostream>

inline int add(int a, int b) {
    return a + b;
}


int main() {
    auto a = 10;
    auto b = 20;

    std::cout << add(a, b) << std::endl;
}

