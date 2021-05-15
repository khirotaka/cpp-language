#include <iostream>


int main() {
    int a = 0;
    float b = 3.14f;
    auto lambda = [=] {
        std::cout << a << std::endl;
    };

    lambda();
}
