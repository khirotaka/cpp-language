#include <iostream>


class Foo {
    int a;
    public:
        Foo() {
            std::cout << "コンストラクタ" << std::endl;
        }
        ~Foo() {
            std::cout << "デコンストラクタ" << std::endl;
        }
};


int main() {
    Foo* pfoo = new Foo{};
//    delete pfoo;
}

