#include <iostream>


class C {
    int default_member;
    
    public:
        int public_member;
    private:
        int private_member;
};

int main() {
    C c;

    // c.default_member = 0;    // エラーが起きる
    c.public_member = 42;   // 公開されているメンバ変数なので、アクセス可能
    // c.private_member = 72;  // 非公開なので、アクセス不可

}

