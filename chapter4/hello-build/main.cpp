#include <iostream>

extern int value;

void show_extern_variable();

int main() {
    std::cout << "main: extern変数アドレス: " << &value << std::endl;
    std::cout << "main: extern変数の値: " << value << std::endl;

    value = 0;

    show_extern_variable();

}

