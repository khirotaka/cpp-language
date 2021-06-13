#include <iostream>


int* local() {
    int i = 42;
    return &i;  
}


int* dyn_alloc() {
    int* ptr = new int;
    *ptr = 42;
    return ptr;     // 動的に確保したものはスコープから出ても破棄されない
}


int main() {
    // int* i = local();    // これはダメ。 local() で作ったものは既に破棄されている。

    int* d = dyn_alloc();
    std::cout << *d << std::endl;
    delete d;       // ここで確保した物を破棄する。
}

