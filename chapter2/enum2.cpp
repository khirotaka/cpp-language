#include <iostream>


enum class Category: char {
    Value1,
    Value2,
    Value3 = 100,
    Value4,
};


int main() {
    Category cat = Category::Value2;

    std::cout << static_cast<int>(cat) << std::endl;
}

