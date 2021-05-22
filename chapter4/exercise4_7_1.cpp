#include <iostream>


namespace module {
    void func() {
        std::cout << "namespace: module" << std::endl;
    }
}


void func() {
    std::cout << "namespace: global" << std::endl;
}


int main() {
    func();
    module::func();
}

