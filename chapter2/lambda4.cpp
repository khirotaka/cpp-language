#include <iostream>


int main() {
    int a = 0;
    auto lambda = [a]() mutable {
        a = 42;
        std::cout << "キャプチャした変数: " << a << std::endl;
    };

    lambda();

    std::cout << "元の変数: " << a << std::endl;

}
