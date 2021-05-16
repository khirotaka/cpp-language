#include <iostream>


class A {
    int m_v;

    public:
        A(int);
        int v() const;
};


A::A(int v) : m_v(v) {
}

int A::v() const {
    return m_v;
}

int main() {
    A x = 42;   // A::A(int) を呼び出している。
    if (x.v() == 42) {
        std::cout << "x.v() は 42 です" << std::endl;
    }
    else { 
        std::cout << "x.v() は 42 ではない" << std::endl;
    }
}

