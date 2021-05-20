#include <iostream>


int main() {
    std::cout << "__FILE__:" << __FILE__ << std::endl;

    std::cout << "__LINE: " << __LINE__ << std::endl;

    std::cout << "_cplusplus: " <<__cplusplus << std::endl;

    int line = __LINE__;

    std::cout << "line: " << ", __LINE__: " << __LINE__ << std::endl;

}

