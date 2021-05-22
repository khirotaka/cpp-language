#include <iostream>


int main() {
    int array[] = {0, 1, 2, 3, 4};

    for (int i=0; i<5; ++i) {
        std::cout << *(array + i) << std::endl;
    }
}

