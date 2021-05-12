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