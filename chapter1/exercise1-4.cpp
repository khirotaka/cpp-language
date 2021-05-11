#include <iostream>

int f(int a) {
    return a + 1;
}

int main() {
    int a = 2;
    if (f(a) == 1) {
        std::cout << "a + 1 は 1です" << std::endl;
    }
    else if (f(a) == 2) {
        std::cout << "a + 1 は 2です" << std::endl;
    }
    else if (f(a) == 3) {
        std::cout << "a + 1 は 3です" << std::endl;
    }
}

