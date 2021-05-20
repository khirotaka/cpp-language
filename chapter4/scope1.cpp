#include <iostream>


class A {
    public:
        ~A();
};

A::~A() {
    std::cout << "デストラクタ呼び出し" << std::endl;
}


void function_scope(int i) {
    A a;
    std::cout << "関数スコープ" << std::endl;

    if (i > 0) {
        return ;
    }
    std::cout << "if文の後" << std::endl;
}

int main() {
    function_scope(10);

    std::cout << std::endl;

    function_scope(-10);


    auto a = 10;

    {
        // 変数 a を宣言 この中では 20
        auto a = 20;
        std::cout << a << std::endl;
    }

    // 変数 a は 10
    std::cout << a << std::endl;

}

