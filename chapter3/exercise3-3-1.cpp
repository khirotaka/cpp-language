#include <iostream>
#include <string>


class Book {
    std::string title;
    std::string writer;
    int price;

    public:
        Book(std::string title, std::string writer, int price);
        Book(const Book& other);
        void print() const;
};


Book::Book(std::string title, std::string writer, int price) : title{title}, writer{writer}, price{price} {
}

Book::Book(const Book& other) : title{other.title}, writer{other.writer}, price{other.price} {
}

void Book::print() const {
    std::cout << title << writer << price << std::endl;
}


int main() {
    Book book{"A", "B", 100};
    book.print();
    Book copy{book};
    copy.print();
}
