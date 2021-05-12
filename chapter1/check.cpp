#include <iostream>


int main() {
    char text[] = "hello, world";

    for (int i=0; i<sizeof(text); ++i) {
        std::cout << text[i] << std::endl;
    }
}

