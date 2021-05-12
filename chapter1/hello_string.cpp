#include <string>
#include <iostream>

int main() {
    std::string hello = "Hello";
    std::cout << hello;     // より長い文字列をあとから代入できる
    hello = ", string";

    std::cout << hello << std::endl;
}
