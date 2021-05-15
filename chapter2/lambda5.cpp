#include <iostream>

int main() {
    int a = 0;
    auto lambda = [&a]() {
        std::cout << "キャプチャした変数: " << a << std::endl;
        ++a;
    };

    lambda();

    std::cout << "元の変数: " << a << std::endl;

    a = 42;

    lambda();
}

