#include <iostream>
#include <string>


class Person {
    std::string m_name;
    int m_age;

    public:
        Person();

        void set_name(std::string name);
        void set_age(int age);

        std::string name() const;
        int age() const;
};

// ここで、 m_age が -1 で初期化される。
Person::Person() : m_age(-1) {
    std::cout << "コンストラクタ呼び出し" << std::endl;
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

    std::cout << "初期化直後の年齢: " << bob.age() << std::endl;
    bob.set_name("bob");
    bob.set_age(20);
    std::cout << "Name: " << bob.name() << std::endl;
    std::cout << "Age: " << bob.age() << std::endl;
}

