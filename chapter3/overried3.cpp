#include <iostream>


class Base {
    public:
        void foo();
};

void Base::foo() {
    std::cout << "基底クラス" << std::endl;
}

class Derived: public Base {
    public:
        using Base::foo;

        void foo(int i);  // 派生クラスでオーバロードを追加
};

void Derived::foo(int i) {
    std::cout << "派生クラス" << std::endl;
}


int main() {
    Derived d;
    d.foo(0);   // 派生クラスの foo()
    d.foo();    // 基底クラスの foo()
}
