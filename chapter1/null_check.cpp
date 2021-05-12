#include <iostream>

int main() {
    int* ptr = nullptr;
    if (ptr == nullptr) {
        std::cout << "ptr は nullpointer" << std::endl;
    }
    else {
        *ptr = 42;
    }
}

