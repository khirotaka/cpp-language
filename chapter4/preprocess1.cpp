#include <iostream>


void hello() {
    std::cout << "Hello, World!" << std::endl;
}


void goodbye() {
    std::cout << "Goodbye" << std::endl;
}

int main() {
    #define hello goodbye       // helloをgoodbye に置き換える

    hello();

    #undef hello
    hello();
}
