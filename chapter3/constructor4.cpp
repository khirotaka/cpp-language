#include <iostream>
#include <string>


class Person {
    std::string m_name;
    int m_age;

    Person(int age);

    public:
        Person();
        Person(std::string name, int age);
        Person(const Person& other); // コピーコンストラクタ

        void set_name(std::string name);
        void set_age(int age);

        std::string name() const;
        int age() const;
};


Person::Person(int age) : m_age(age) {
    std::cout << "共通コンストラクタ" << std::endl;
}

Person::Person() : Person(-1) {
    std::cout << "引数なしコンストラクタ" << std::endl;
}

Person::Person(std::string name, int age) : Person(age) {
    std::cout << "引数付きコンストラクタ" << std::endl;
    set_name(name);
}

// コピーコンストラクタ
Person::Person(const Person& other) {
    std::cout << "コピーコンストラクタ" << std::endl;
    set_name(other.name());
    set_age(other.age());
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
    Person alice("alice", 15);
    Person copy(alice);     // コピーコンストラクタ呼び出し
    std::cout << copy.name() << std::endl;
    std::cout << alice.name() << std::endl;
}

