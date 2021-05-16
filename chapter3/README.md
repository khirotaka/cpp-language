# Class

## const メンバ関数とmutable

**`const` メンバ関数** ... インスタンスが `const` でも呼び出し可能なメンバ関数のこと。

```cpp
class ClassName {
    public:
        ReturnType member_func(params, ...) const;
};


ReturnType member_func(params, ...) const {
    body...
}
```

### const/非constメンバ関数のオーバーロード

`const` がついているかどうかでも、**オーバーロード** ができる。

```cpp
class Foo {
    int a;
    public:
        int get_a();
        int get_a() const;
};


int Foo::get_a() {
    std::cout << "Not const" << std::endl;
    return a;
}

int Foo::get_a() const {
    std::cout << "const" << std::endl;
    return a;
}
```

上の場合、インスタンス自体が `const` か、`非const` かで評価される。

### constメンバ関数でも書き込む場合
キャッシュを作成するよう場合有効。

メンバ変数を `mutable` 指定することで、 `const` メンバ関数からでも書き換える操作ができるようになる。


## コンストラクタ・デストラクター
### コンストラクタ
Pythonでいう `__init__()` 。


```cpp
class ClassName {
    public:
        ClassName();    // コンストラクタの宣言
};

ClassName::ClassName() : member(init-value), member(init-value), ... {
    body
}
```

上の `: member(value), member(value), ...` の ` : ` は、**メンバ初期化リスト** 


### デストラクター
コンストラクタは、正常に動作するために、メンバ変数位がにも必要であれば、追加でメモリ領域を確保する。  
プログラム内で適切にメモリ領域を解放しないと、やがてメモリ不足(メモリリーク)に陥る。

これを解決するには、デストラクタを用いる。デストラクタはインスタンスが破棄されるときに呼ばれる。
インスタンスが破棄されるタイミングは、関数本体などの `{` が閉じるタイミング。 

```cpp
class ClassName {
    public:
        ~ClassName();   // デストラクタの宣言
};

ClassName::~ClassName() {
    body
}
```


#### RAII
コンストラクタでメモリ確保して、デストラクタで解放することを **RAII** (Resource Acquisition Is Initialization) という。


## 初期値を受け取るコンストラクタ

```cpp
class ClassName {
    public:
        ClassName(params, ...);
};

ClassName variable(args, ...);
```

この形を取ると、コンパイラが自動生成する **デフォルトコンストラクタ** がなくなってしまう。  
**デフォルトコンストラクタ**は、引数がないコンストラクタ、通常はコンパイラが自動的に定義する。  
プログラマがこれを定義すると、そちらが使われる。

### 移譲コンストラクタ
コンストラクタの内部のみで使える、他のコンストラクタを呼び出す為の専用方法。

1. 移譲先コンストラクタが呼ばれる
2. 処理が行われた後、移譲元のコンストラクタの処理が行われる。

移譲コンストラクタの場合、メンバ変数の初期化は移譲先でしかできない

```cpp
class ClassName {
    public:
        ClassName(params, ...); // 移譲元コンストラクタの宣言
};

ClassName::ClassName(params, ...) : ClassName(args, ...) { // 移譲先コンストラクタの呼び出し
    body;
}
```

### コピーインストラクタ
コンストラクタには、
1. ユーザ定義コンストラクタ
2. コンパイラ生成コンストラクタ

がある。コンパイラ生成コンストラクタの中には、クラスをコピーする際に使われる**コピーコンストラクタ** が存在する。


```cpp
class ClassName {
    public:
        ClassName(const ClassName& variable);   // コピーコンストラクタ
};
```

メモリ領域やリソースを扱うクラスの場合、コピーコンストラクタをプログラマが定義する必要がある。  

メンバ変数がポインタ変数の場合、コンパイラが生成するコピーでは、ポインタ変数の値(アドレス) のみコピーを行い、
ポインタ変数が指し示す先の実際のオブジェクトはコピーしない。

これは、ポインタ変数の値のみコピーすると、オブジェクトは1つしかないのに、複数のクラスが同じアドレス値をもっていることになり、
それらオブジェクトが破棄されるたびに、それぞれ同じオブジェクトを解放しようとする、**二重解放** が起きる。


### explicit 指定子
**暗黙のコンストラクタ呼び出し** が発生することを防ぐために、`explicit` 演算子 を追加する.

```cpp
class A {
    int m_v;

    public:
        explicit A(int);    // 暗黙のコンストラクタ呼び出しを禁止できる
        int v() const;
};

A::A(int v) : m_v(v) {
}

int A::v() const {
    return m_v;
}

int main() {
    A x = 0;    // ERROR
    A y(42);    // OK
};
```
