#include <iostream>


struct product {
    int id;
    int price;
    int stock;
};


int main() {
    // product pen;
    // pen.id = 0;
    // pen.price = 100;
    // pen.stock = 200;

    // こういう風に定義することもできる
    product pen = {
        0, // 商品ID
        100, // 価格
        200, // 在庫
    };

    product* ptr = &pen;

    std::cout << "商品ID " << ptr->id << std::endl;
    std::cout << "単価 " << ptr->price << std::endl;
    std::cout << "在庫数 "  << ptr->stock << std::endl;
}

