#include <iostream>

int one() {
    return 1;
}

int main() {
    auto d = 3.14;  // 3.14はdouble、d は double
    d = 2.71f;      // 2.71f は float型、double型に推論された d に問題なく格納できる

    std::cout << d << std::endl;

    auto i = one(); // one() の戻り値は int なので、 int

    std::cout << i << std::endl;
}
