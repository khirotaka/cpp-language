#include <iostream>
#include <string>

class Person {
    std::string m_name;
    int m_age;

    public:
        Person();
        ~Person();

        void set_name(std::string name);
        void set_age(int age);

        std::string name() const;
        int age() const;
};

Person::Person() : m_age(-1) {
    std::cout << "コンストラクタ呼び出し" << std::endl;
}

Person::~Person() {
    std::cout << "デストラクタ呼び出し" << std::endl;
}

void Person::set_name(std::string name) {
    m_name = name;
}

void Person::set_age(int age) {
    m_age = age;
}


std::string Person::name() const {
    return m_name;
}


int Person::age() const {
    return m_age;
}


int main() {
    Person bob;
    bob.set_name("bob");
    bob.set_age(20);
    std::cout << "main()関数の最後" << std::endl;
    // ここで、bobのデストラクタが呼ばれる。
}
