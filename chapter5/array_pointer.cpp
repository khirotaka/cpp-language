#include <iostream>

int main() {
    int array[5] = {0, 1, 2, 3, 4};
    int (*ptr)[5] = &array;

    for (int e : *ptr) {
        std::cout << e << std::endl;
    }

    std::cout << std::endl;

    int (&ref)[5] = array;

    for (int e : ref) {
        std::cout << e << std::endl;
    }
}

