#include <iostream>

int main() {
    const int constant = 42;
    const int& ref_const = constant;

//    constant = 0;   // Error
//    ref_const = 0; // Error

    int value = 72;
    int& ref = value;   // 通常の参照
    const int& cref = value;    // constな参照

    value = 0;  // 変数自体はconstじゃない
    ref = 0;    // const指定されていない三章からも変更可能
//    cref = 0;   // Error この参照は、const指定
}

