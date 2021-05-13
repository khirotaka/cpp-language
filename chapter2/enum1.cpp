#include <iostream>

enum class Category {
    Value1,     // 先頭は明示的に指定しない限り暗黙的に 0
    Value2,     // 値を省略した場合は 1つ上の整数の次 (この例だと 1)
    Value3 = 100,
    Value4,     // 再度省略した場合には、1つ上の整数に次 (これは 101)
};


int main() {
    Category cat = Category::Value3;

    // 列挙体の値に対応した整数
    std::cout << static_cast<int>(cat) << std::endl;
}

