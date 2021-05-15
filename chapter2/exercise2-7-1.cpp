#include <iostream>


void show_value(int a) {
    std::cout << a << std::endl;
}

int sum(int a, int b, int c) {
    int d = a + b + c;
    return d;
}

int sum(int a, int b) {
    return sum(a, b, 0);
}

int sum(int a, int b, int c, int d) {
    return a + b + c + d;
}


int main() {
    int x = sum(10, 20);
    show_value(x);

    int y = sum(5, 15, 25);
    show_value(y);

    int z = sum(10, 20, 30, 40);
    show_value(z);

}

