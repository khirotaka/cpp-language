#include <iostream>

int main() {
    int value = 42;
    std::cout << "value のアドレスは " << &value << " で、値は " << value << " です." << std::endl;

    int& reference = value;

    std::cout << "referenceのアドレスは " << &reference << " で、値は " << reference << " です" << std::endl;

    reference = 0;

    std::cout << "valueのアドレスは" << &value << " で、値は " << value << " です" << std::endl;
}

