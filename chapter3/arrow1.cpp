#include <iostream>


class A {
    public:
        void foo();
};

void A::foo() {
    std::cout << "A::foo()" << std::endl;
}

void call_foo(A* pa) {
    pa->foo();
    // (*pa).foo() もOK
}

int main() {
    A a;
    call_foo(&a);
}

