#include <iostream>


class vector3d {
    public:
        using Type = int;
        vector3d::Type get_x();
        vector3d::Type get_y();
        vector3d::Type get_z();

        void set_x(vector3d::Type new_x);
        void set_y(vector3d::Type new_y);
        void set_z(vector3d::Type new_z);

    private:
        vector3d::Type x;
        vector3d::Type y;
        vector3d::Type z;
};


vector3d::Type vector3d::get_x() {
    return x;
}

vector3d::Type vector3d::get_y() {
    return y;
}

vector3d::Type vector3d::get_z() {
    return z;
}

void vector3d::set_x(vector3d::Type new_x) {
    x = new_x;
}

void vector3d::set_y(vector3d::Type new_y) {
    y = new_y;
}

void vector3d::set_z(vector3d::Type new_z) {
    z = new_z;
}


vector3d set(vector3d::Type x, vector3d::Type y, vector3d::Type z) {
    vector3d vec;
    vec.set_x(x);
    vec.set_y(y);
    vec.set_z(z);

    return vec;
}


vector3d set(vector3d::Type x, vector3d::Type y) {
    vector3d vec;
    vec.set_x(x);
    vec.set_y(y);
    vec.set_z(0);

    return vec;
}


int main() {
    vector3d vec;
    vector3d::Type tmp;

    std::cout << "Set x: ";
    std::cin >> tmp;
    vec.set_x(tmp);

    std::cout << "Set y: ";
    std::cin >> tmp;
    vec.set_y(tmp);

    std::cout << "Set z: ";
    std::cin >> tmp;
    vec.set_z(tmp);

    std::cout << "x: " << vec.get_x() << std::endl;
    std::cout << "y: " << vec.get_y() << std::endl;
    std::cout << "z: " << vec.get_z() << std::endl;

    auto vec2 = set(1, 2);

    std::cout << "x: " << vec2.get_x() << std::endl;
    std::cout << "y: " << vec2.get_y() << std::endl;
    std::cout << "z: " << vec2.get_z() << std::endl;
}

