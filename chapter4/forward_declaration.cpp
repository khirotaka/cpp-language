#include <iostream>


std::string get_message();

int main() {
    auto msg = get_message();
    std::cout << msg << std::endl;
}

std::string get_message() {
    return "Hello, forward declaration";
}

