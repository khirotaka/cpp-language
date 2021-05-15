#include <iostream>

/*
void show_value(int v) {
    std::cout << v << std::endl;
}
*/

int main() {
    auto show_value = [](int v) -> void {
        std::cout << v << std::endl;
    };
    show_value(42);
}

