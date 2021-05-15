#include <iostream>

int main() {
    // 変数 show に lambda 式を代入
    auto show = [](int i) -> void {
        std::cout << "i の値は " << i << " です。" << std::endl;
    };

    show(42);
}

