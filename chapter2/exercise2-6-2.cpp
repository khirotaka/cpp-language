#include <iostream>
#include <string>

int main() {
    std::string str;
    std::cout << "1行文字列を入力: ";
    std::getline(std::cin, str);
    std::cout << str << std::endl;
}
