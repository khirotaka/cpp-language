#include <iostream>


class Base {
    virtual void foo();
};


void Base::foo() {
    std::cout << "Base::foo(); " << std::endl;
}

class Derived: public Base {
    public:
        void foo() override;
        void foo(int i);
};

void Derived::foo() {
    std::cout << "Derived::foo() override" << std::endl;
}

void Derived::foo(int i) {
    std::cout << "Derived::foo(int)" << std::endl;
}

int main() {
    Derived derived;
    derived.foo();      // 仮想関数呼び出し
    derived.foo(42);    // 仮想関数ではないオーバーロードの呼び出し
}

