#include <iostream>
#include <vector>


int main() {
    std::vector<int> empty;
    std::cout << "empty.size(): " << empty.size() << std::endl;
    std::vector<int> array = {10, 20, 30, 40, 50,};
    std::cout << "array.size(): " << array.size() << std::endl;


    for (int e : array) {
        std::cout << e << std::endl;
    }
}

