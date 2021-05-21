#include <iostream>


int value = 42;

void show_extern_variable() {
    std::cout << "extern変数のアドレス: " << &value << std::endl;
    std::cout << "extern変数の値: " << value << std::endl;
}

