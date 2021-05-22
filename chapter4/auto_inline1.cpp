#include <iostream>


class A {
    int i;

    public:
        A() : i(0) {}

        void set_i(int i) {
            this->i = i;
        }

        void show() const {
            std::cout << i << std::endl;
        }
};


int main() {
    A a;
    a.show();
    a.set_i(123);
    a.show();
}
