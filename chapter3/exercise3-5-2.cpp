#include <iostream>
#include <string>

class Base {
    public:
        virtual std::string name() const;
};


std::string Base::name() const {
    return "Base";
}


class Derived : public Base {
    public:
        std::string name() const override;
};


std::string Derived::name() const {
    return "Derived";
}

class MoreDerived : public Derived {
    public:
        std::string name() const;
};


std::string MoreDerived::name() const {
    return "MoreDerived";
}


int main() {
    MoreDerived more;
    std::cout << more.name() << std::endl;
}

