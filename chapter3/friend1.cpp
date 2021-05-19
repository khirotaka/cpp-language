#include <iostream>


class vector3d {
    float x;
    float y;
    float z;

    public:
        vector3d();
        explicit vector3d(float x, float y, float z);
        friend vector3d add(const vector3d& lhs, const vector3d& rhs);  // friend関数のプロトタイプ宣言
        void dump() const;
};

vector3d::vector3d() : vector3d(0, 0, 0) {
}

vector3d::vector3d(float x, float y, float z) : x(x), y(y), z(z) {
}

// 定義には friend 不要
// これは、vector3d を返す関数であって、メンバ関数ではない。
vector3d add(const vector3d& lhs, const vector3d& rhs) {
    vector3d result;
    result.x = lhs.x + rhs.x;
    result.y = lhs.y + rhs.y;
    result.z = lhs.z + rhs.z;

    return result;
}

void vector3d::dump() const {
    std::cout << x << ", " << y << ", " << z << std::endl;
}

int main() {
    vector3d a(1, 1, 1), b(1, 2, 3);
    vector3d c = add(a, b);     // フレンド関数呼び出し
    c.dump();
}

