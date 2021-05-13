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
