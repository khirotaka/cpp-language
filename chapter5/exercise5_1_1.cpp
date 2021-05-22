#include <iostream>

void reverse(int* array, int size);

int main() {
    int array[] = {0, 1, 2, 3, 4};

    reverse(array, 5);

    std::cout << array[0] << std::endl;
    std::cout << array[1] << std::endl;
    std::cout << array[2] << std::endl;
    std::cout << array[3] << std::endl;
    std::cout << array[4] << std::endl;
}


void reverse(int* array, int size) {
   for (int i=0; i<size / 2; ++i) {
        int tmp = array[i];
        array[i] = array[size - i - 1];
        array[size - i - 1] = tmp;
    }
}

