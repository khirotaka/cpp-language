#include <iostream>


class product {
    int price;

    public:
        product(int price) : price(price) {
        }

        inline int get_price() const {
            return price;
        }
        inline void set_price(int price) {
            this->price = price;
        }
};

int main() {
    product p(10);
    std::cout << p.get_price() << std::endl;
    p.set_price(1);
    std::cout << p.get_price() << std::endl;
}

