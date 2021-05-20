#include <iostream>


class A {
    int m_v;

    public:
        explicit A(int x) : m_v(x) {};
        int v() const {
            return m_v;
        }
};


int main() {
    A y(42);
    std::cout <<y.v() << std::endl;

}

