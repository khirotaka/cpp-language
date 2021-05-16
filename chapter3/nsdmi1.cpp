#include <iostream>
#include <string>


class S {
    public:
        int answer = 42;
        float pi{ 3.14159265f };
};

struct Book {
    std::string title = "untitled";
    int isbn = 0;
};

int main() {
    S s;
    std::cout << "s.answer: " << s.answer << std::endl;
    std::cout << "s.pi: " << s.pi << std::endl;
    Book b;
    std::cout << "s.title: " << b.title << std::endl;
    std::cout << "s.isbn: " << b.isbn << std::endl;
}

