#include <iostream>
#include <string>

class Base {
    public:
        virtual std::string name() const;
        virtual std::string most_name() const = 0;
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
        std::string name() const override;
        std::string more_name() const override;
};


std::string MoreDerived::name() const {
    return "MoreDerived";
}

std::string MoreDerived::more_name() const {
    return "more name()";
}

int main() {
    Derived more;
}

