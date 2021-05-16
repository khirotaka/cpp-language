#include <iostream>


class A {
    int v;

    public:
        void set(int value);
        const int& get() const;
        int& get();
};

void A::set(int value) {
    v = value;
}

int& A::get() {
    return v;
}

const int& A::get() const {
    return v;
}


int main() {
    A a;
    a.set(42);
    const A& ca = a;    // constな参照
    A& ra = a;
    ca.get();
    ra.get();
}

