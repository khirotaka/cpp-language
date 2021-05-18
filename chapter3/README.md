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

## デフォルトの初期値
Pythonでいう

```python
class A:
    def __init__(self):
        self.a = 0
```

ってやってるだけ。


### メンバ変数の初期値
メンバ変数のデフォルト値を指定するには次の方法がある。
この公文は、**非静的メンバ変数の初期化子** (Non Static Data Member Initializer: NSDMI) という名称が付いている。

```cpp
class ClassName {
    TypeName variable = default;
    TypeName variable = { default };
    TypeName variable(default);
    TypeName variable{default};
};
```

### メンバ初期化リストと初期値
NSDMIとコンストラクタのメンバ初期化リストの両方がある場合、コンストラクタで指定した初期値の方を使って初期化される。 


## 継承
Pythonでいう

```python
class DerivedClass(BaseClass):
    ...
```

は、

```cpp
class DerivedClass : AccessSpecifier BaseClass {
    ...
};
```

`AccessSpecifier` は、継承クラスが `public` で公開しているメンバを派生クラスでも `public` で公開する意味。

### オーバライド
存在する機能の「処理内容」を変えるには、 **オーバライド**する。しかし、なんでもオーバライド できるわけではなく、
基底クラス定義時に、「派生クラスで変更可能」という宣言をしておく必要がある。この宣言がなされたメンバ関数のことを**仮想関数**
と呼ぶ。  
なお、**オーバライド** するには、 `override` 指定子をつける。な、**オーバライド** はあくまで処理だけを書き換えられる。引数は変更できない。

```cpp
class BaseClass {
    public:
        virtual ReturnType function(params, ...);
};

ReturnType BaseClass::function(params, ...) {
    // virtualは書かない
}

class DerivedClass : public BaseClass {
    public:
        ReturnType function(params, ...) override {
            // 仮想関数のオーバライド
        }
};

ReturnType DerivedClass::function(params, ...) {
    body;
}
```

なお、基底クラスで `virtual` 指定しておけば、派生クラスで`override`指定子を省略してもオーバライドできる。
しかし、開発しているうちに基底クラスのメンバ関数の仕様が変更された場合、メンバ関数が仮想関数で無くなったりすることも考えられる。
このような、ミスを回避するために、オーバライドするつもりのメンバ関数に `override` と指定することで、もし規定クラスから無くなっていた場合でも、
エラーを出してくれる。意識的にこの`override` 指定子をつけた方が良い。

### 名前の隠蔽
基底クラスが持っているメンバ関数と同じ名前のメンバ関数を派生クラスに追加すると、発生する。
これが起こると、基底クラスのメンバ関数を呼ぶことができなくなる。
名前の隠蔽は、派生クラスでオーバライドを追加しようとした時に起こる。

こういった場合、 `using` 宣言を使うと、基底クラスのメンバ関数をオーバロードとして追加できる。

```cpp
class ClassName : AccessSpecifier BaseClass {
    public:
        using BaseClass::member_func;
};
```

型名に別名をつける際に利用した `using` 宣言とは別物。

### 純粋仮想関数と抽象クラス
規定クラスでは宣言のみで、処理内容がなく、派生クラスが必ずオーバライドして処理を書くように強制させる **純粋仮想関数** がある。
PyTorch の `torch.nn.Module` (?)

```cpp
class ClassName {
    public:
        virtual ReturnType function(params, ...) = 0;   // 純粋仮想関数
};
```

#### 純粋クラス
純粋仮想関数が宣言されたクラスは **抽象クラス** と呼ばれる。

```cpp
class AbstractClass {
    public:
        virtual void foo() = 0;
};
```

Javaの `Interface` や Swiftの `Protocol` の真似するためにこの抽象クラスを使うのは、
パフォーマンスの面からみてあまり好ましくない。


## オブジェクトポインタ
ポインタを経由して、メンバにアクセスする際は、`struct` と同じく`->` を使う。
