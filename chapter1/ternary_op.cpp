#include <iostream>

int absolute_1(int value) {
    int abs;
    if (value < 0) {
        abs = - value;
    }
    else {
        abs = value;
    }
    return abs;
}


int absolute_2(int value) {
    int abs = value < 0 ? -value : value;
    return abs;
}

int main() {
    std::cout << "if文を使う場合" << std::endl;
    std::cout << absolute_1(-1) << std::endl;
    std::cout << absolute_1(-1) << std::endl;

    std::cout << "---------- " << std::endl;

    std::cout << "三項演算子を使う場合" << std::endl;
    std::cout << absolute_2(-1) << std::endl;;
    std::cout << absolute_2(-1) << std::endl;
    
    return 0;
}
