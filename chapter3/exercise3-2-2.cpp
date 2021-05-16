#include <iostream>


class A {
    private:
        int a;
    public:
        A();
        ~A();
};


A::A() : a(-1) {
    std::cout << "コンストラクタ" << std::endl;
}

A::~A() {
    std::cout << "デストラクタ" << std::endl;
}


int main() {
    A a;
}

