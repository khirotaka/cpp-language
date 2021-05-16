#include <iostream>
#include <string>


class Person {
    std::string m_name;
    int m_age;

    Person(int age);

    public:
        Person();
        Person(std::string name, int age);

        void set_name(std::string name);
        void set_age(int age);

        std::string name() const;
        int age() const;
};



Person::Person(int age) : m_age(age) {
    // 複数のコンストラクタで共通の大本の処理を private なコンストラクタで定義、
    // 移譲コンストラクを使うことで、一貫した初期化手段を提供
    std::cout << "共通コンストラクタ呼び出し" << std::endl;
}


// 移譲元コンストラクタ(引数なし)
Person::Person() : Person(-1) { // <- 移譲先コンストラクタが呼び出されている
    std::cout << "引数なしコンストラクタ" << std::endl;
}

// 移譲元コンストラクタ(引数あり)
Person::Person(std::string name, int age) : Person(age) {   // <- 移譲先コンストラクタが呼び出されている
    std::cout << "引数付きコンストラクタ" << std::endl;
    set_name(name); // 初期化時にメンバ関数を呼び出せる。
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
    std::cout << alice.name() << std::endl;

    Person bob;
    bob.set_name("bob");
    bob.set_age(10);

    std::cout << bob.name() << std::endl;
}

