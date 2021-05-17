#include <iostream>


class Base {
    public:
        void public_member();
};

void Base::public_member() {
    std::cout << "基底クラス" << std::endl;
}

class Derived: public Base {
    public:
        void public_member(int i);  // 派生クラスでオーバロードを追加
};

void Derived::public_member(int i) {
    std::cout << "派生クラス" << std::endl;
}


int main() {
    Derived d;
    d.public_member(0);
    // d.public_member();  // Error
}
