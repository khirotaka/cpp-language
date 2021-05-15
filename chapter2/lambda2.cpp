#include <iostream>


int main() {
    int a = 0;
    auto lambda = [a]() {
        std::cout << a << std::endl;
    };

    lambda();

    a = 42;
    // lambda式内にある a はコピーされたものだから、別物。
    // つまり、以下の出力は 0

    lambda();
}
