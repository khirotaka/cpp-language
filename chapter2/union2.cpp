#include <iostream>


union U {
    int a;
    int b;
    int c;
};

int main() {
    U u = { 42 };   // 先頭メンバで初期化

    std::cout << "u.bの値 " << u.b << std::endl;

    // u.c も u.a ・ u.bと同じ場所にある
    // u.c を使って変更すると他のメンバ変数も変更される
    u.c = 1024;

    std::cout << "u.aの値 " << u.a << std::endl;
}

