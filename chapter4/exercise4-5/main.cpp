#include <iostream>
#include "module.hpp"

extern int value;

int main() {
    value = 20;
    show_value();
}

