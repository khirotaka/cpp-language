#include <iostream>

int main() {
    int array[] = {0, 1, 2, 3, 4};
    // 配列の要素の型に推論される
    for (auto e: array) {
        std::cout << e << std::endl;
    }
}

