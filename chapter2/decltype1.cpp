#include <iostream>

decltype(1) one() {
    return 1;
}

int main() {
    auto i = one();
    decltype(i) j;  // decltype の所は int になっている

    j = 42.195;     // 暗黙の型変換が行われ、int になる

    std::cout << j << std::endl;
}

