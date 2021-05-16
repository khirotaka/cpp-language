#include <iostream>
#include <string>

class Book {
    std::string title = "";
    int page = 0;

    public:
        Book();
        explicit Book(std::string title, int page);

        void show() const;
};


Book::Book() : title("untitled") {
}

Book::Book(std::string title, int page) : title(title), page(page) {
}

void Book::show() const {
    std::cout << title << " " << page << "ページ" << std::endl;
}

int main() {
    Book nsdmi;
    nsdmi.show();

    Book old_edition("Book old", 100);

    old_edition.show();
}

