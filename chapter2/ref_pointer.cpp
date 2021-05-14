#include <iostream>

int main() {
    int value = 42;
    int other = 0;

    int* pointer = &value;
    int& reference = value;

    std::cout << "value のアドレスは " << &value << " で、値は " << value << " です。" << std::endl;
    std::cout << "otherのアドレスは " << &other << " で、値は " << other << " です。" << std::endl;

    std::cout << "pointerの持つアドレスは " << pointer << " で、値は、 " << *pointer << " です。" << std::endl;
    std::cout << "referenceのアドレスは " << &reference << " で、値は " << reference << " です。" << std::endl;

    pointer = &other;    // ポインタが持つアドレスを other のアドレスに変更
    reference = other;

    std::cout << std::endl;

    std::cout << "value のアドレスは " << &value << " で、値は " << value << " です。" << std::endl;
    std::cout << "otherのアドレスは " << &other << " で、値は " << other << " です。" << std::endl;

    std::cout << "pointerの持つアドレスは " << pointer << " で、値は、 " << *pointer << " です。" << std::endl;
    std::cout << "referenceのアドレスは " << &reference << " で、値は " << reference << " です。" << std::endl;
}
