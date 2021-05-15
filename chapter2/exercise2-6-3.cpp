#include <iostream>
#include <string>


int main() {
    std::string str;

    do {
        std::cout << ">> ";
        std::getline(std::cin, str);
        std::cout << "文字列: " << str << std::endl;
    } while(str != "");
}

