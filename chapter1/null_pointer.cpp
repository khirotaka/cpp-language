#include <iostream>


int main() {
    int* ptr = 0;   // ヌルポインタで初期化

    std::cout << ptr << std::endl;  // ポインタ変数が持っているアドレスを表示

    ptr = nullptr;  // ヌルポインタリテラルを代入

    std::cout << ptr << std::endl;
}
