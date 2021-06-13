#include <iostream>
#include <string>

class Product {
    int id;
    std::string name;
    int price;

    public:
        explicit Product(int id, std::string name, int price) : id(id), name(name), price(price) {
        }
};


int main() {
    Product p[4] = {
        Product(1, "smart phone", 60000),
        Product(2, "Tablet", 40000),
        Product(3, "smart phone", 60000),
        Product(4, "Tablet", 40000),
    };
}
