#include <iostream>


class A {
    int value;
    public:
        void set_value(int value);
        int get_value() const;
        int get_value2() const;
};


void A::set_value(int value) {
    this->value = value;
}

int A::get_value() const {
    return value;
}

int A::get_value2() const {
//    this->value = 0;  //Error, this は const A* なので、変更不可
//    this->set_value(0);   // Error, const修飾していないメンバ関数も呼べない

    return this->get_value();   // OK, constメンバ関数からconstメンバを呼ぶことはできる。
}

int main() {
    A a;
    a.set_value(10);
    std::cout << a.get_value2() << std::endl;
}
