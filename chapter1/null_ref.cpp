#include <iostream>


int main() {
    int* ptr = nullptr;

    *ptr = 42;  // ヌル参照
    std::cout << "null参照の後" << std::endl;
}

