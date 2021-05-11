#include <iostream>

int sum(int a, int b, int c) {
    int ab = a + b;
    int abc = ab + c;
    return abc;
}

int main() {
    std::cout << "sum(5, 1, -2): " << sum(5, 1, -2) << std::endl;
}
