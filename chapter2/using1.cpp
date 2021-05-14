#include <iostream>


using integer = int;

integer main() {
    int value = 42;
    using number = integer; // さらに別名をつけることができる
    number num = 0;

    value = num;
}


