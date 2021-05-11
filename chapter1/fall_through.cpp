#include <iostream>

int main() {
    int a = 2;
    switch (a) {
        case 1: // Fall Through
        case 2: // Fall Through
        case 3:
            std::cout << "aは1か2か3です。" << std::endl;
            return 0;
    }
    std::cout << "起こりの処理" << std::endl;
}

