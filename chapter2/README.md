# 基本的な言語機能

## 構造体・共用体・列挙体

### 構造体
複数の変数を1つに纏めて扱う為の型を作る機能。

構造体のメンバにアクセスするには、 **ドット演算子** と **アロー演算子** を使う。

* ドット演算子 ... アクセス先の構造体が構造体変数
* アロー演算子 ... 構造体変数へのポインタ

### 共同体
構造体同様メンバ変数を持っているが、それらが全て同一のアドレス上に存在している。  
複数のメンバ変数が同一アドレス上に存在している為、どれか１つ書き換えた場合、他のメンバ変数も全て書き変わる。

`union` を使って定義する。

```cpp
union NAME {
    type member1;
    type member2;
    ...
};
```

### 列挙体
「列挙体が取り得る値を列挙しておき、そのうちいずれかの値を持っている」変数を作る為の型

```cpp
enum class EnumName {
    item1,
    item2 = value,
    ...
};
```

値を取得するには、 **スコープ解決演算子** を使う。

例)
```cpp
EnumName::item;
```


列挙体が扱える整数の範囲を指定するには以下のようにする。


```cpp
enum class EnumName : UnderlyingType {
    item1,
    item2 = value,
    ...
};
```

`UnderlyingType` は `enum` で扱うベースとなる整数型を指定する。
利用できるには、組み込むの整数型のみ。

`char` 型は 1バイトであることが決まっているので以下のようなことができる。

```cpp
enum class Category : char {
    Value1,
    Value2,
    Value3 = 100,
    Value4,
};

Category cat = Category::Value2;

static_cast<int>(cat);  // enumは、こうやらないとエラーが出る。
```


## クラス

### アクセス演算子
データや処理には、他の処理から使われるためのものと、クラス内の他の処理で使う為のものとがある。
内部処理の用のデータが外部からアクセスできると問題が発生するかもしれない。  
アクセス制御する為の演算子が **アクセス指定子** 

C++のクラスでは、デフォルトで全てのメンバ変数・関数が外部からアクセスできない *private* になっている。  
後悔するには、明示的に指定する必要がある。


```cpp
class ClassName {
public:
    // 公開するメンバ変数・関数

private:
    // 非公開なメンバ変数・関数
};
```


### メンバ関数

```cpp
class ClassName {
    ReturnType member-function-name(params, ...);
};



ReturnType member-function-name(params, ...) {
    body
};


// ...

instance.member-function-name(args, ...);
// インスタンスへのポインタ経由でのメンバ関数呼び出し
pointer->member-function-name(args, ...);
```


`class` の定義でメンバ関数の名前だけ定義しているのは、プロトタイプ宣言的なもの？  

## 参照
変数に別名をつける機能。ある変数 `a` があったときに、 `b` という名前で参照を作ることで、
`a` をつかっても、`b` 使っても同じ変数を指し示すようになる。

```cpp
TypeName& reference-name = variable-name;
```

参照は変数への別名、必ず初期化が必要。

### 参照とポインタの違い
- ポインタは、変数の場所をアドレスとして、保存する機能。
- 参照は、変数の直接の別名。間接参照演算子(`*`) を使わなくても変数にアクセスできる。

### const参照
参照先の変数が `const` 指定されているにもかかわらず、参照を使うと変更できてしまうのは困るので、
参照する場合は、 `const` 参照を使う。

`const` 参照は関数の引数として、クラスや構造体を受け取る場合などでよく使われる。


## 型推論

```cpp
auto VariableName = InitialiValue;
```

この形の型推論が使えるのは、初期値がある場合のみ。


### 範囲for文の型推論
型推論は基本的に初期値が必要だが、一部例外があり、1つが **範囲for文**。
**範囲for** で走査するときに得られる各要素の型に ``auto`` と書くと、要素の型を推論した上でループする。


### 式の型を推論する
式から型を得る
```cpp
decltype(expression)
```

これを型の代わりに使って、変数宣言なども行える。


### 配列の型推論
**型推論を使うことでは、配列を宣言できない**

```cpp
// autoの配列は作れない
auto a[] = {0, 1, 2, }; // ERROR
auto a[] {0, 1, 2, };   // ERROR

auto array = {0, 1, 2, } // 配列ではない別物ができる std::initializer_list<int> 型
```

## 型の別名定義
Pythonでいう`as` (?)

`using` 宣言

```cpp
using NewTypeName = OldTypeName;
```

なお、`using` 宣言で型に別名を与えても、元の名前を使うことができる。

C言語にも似たような機能がある。

```c
typedef OldTypeName NewTypeName;
```
なお、`using` 宣言とは順番が逆なことに注意



### ネストした型名
構造体・クラスはメンバ変数・メンバ関数以外に、ネストした型名を持つことができる。

```cpp
class ClassName {
    public:
        using NestedTypeName = TypeName;
};

ClassName::NestedTypeName value_name;
```



