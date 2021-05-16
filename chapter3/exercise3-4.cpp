#include <iostream>


class vector3d {
    float x = 0;
    float y = 0;
    float z = 0;

    public:
        vector3d();
        void show() const;
};


vector3d::vector3d() {
}

void vector3d::show() const {
    std::cout << x << y << z << std::endl;
}

int main() {
    vector3d v;
    v.show();
}

