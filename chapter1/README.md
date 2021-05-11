# Chapter 1

## 変数の宣言

変数宣言と初期化を同時に行うには４種類ほど方法がある。


```
type-name variable-name(initial-value);

type-name variable-name = initial-value;

type-name variable-name{initial-value};

type-name variable-name = {initial-value};
```

例
```cpp
int main() {
    int a(10);
    int b = 10;
    int c{10};
    int d = {10};
}
```

### const
定数にするには `const` を使う。宣言方法は２通りある。

```cpp
const TypeName VarName = init-value;
TypeName const VarName = init-value;
```

## 演算子
「前置」と「後置」
- 前置 ... 変数に1を足す/引くをして、その値を返す
- 後置 ... 変数に1を足す/引くするが、返すのは足し引きする前の値

例)
```cpp
#include <iostream>

int main() {
    int i = 42;

    std::cout << "++i: " << ++i << std::endl; // 前置
    std::cout << "i: " << i << std::endl;
    std::cout << "i++: " << i++ << std::endl;
    std::cout << "i;" << i << std::endl;
}
```

これの実行結果は

```
++i: 43
i: 43
i++: 43
i;44
```

### 三項演算子
条件分岐ができる演算子。三項演算子は `true` だった場合、 `false` だった場合の
それぞれの指揮を受け取って、条件によってそのどちらか片方を返す演算子。

**構文**

```
condition ? true-expression : false-expression
```

#### 三項演算子を使わない場合

```cpp
int absolute(int value) {
    int abs;
    if (value < 0) {
        abs = -value;
    } 
    else {
        abs = value;
    }
    return abs;
}
```

#### 三項演算子を使う場合

```cpp
int absolute(int value) {
    int abs = value < 0 ? -value : value;
    return abs;
}
```

## 組み込み型

### 浮動小数点

```cpp
float pi = 3.141529f;   // 最後に f を付けると float型になる
double e = 2.7182;      // 何も付かないただの実数は double型になる
```

### リテラル
プログラムの中に直接記述できるデータのこと。文字リテラルや数値リテラルのほかに、
文字列リテラル、ユーザ定義リテラルもある。

```cpp
0       // 数値リテラル
'0'     // 文字リテラル
"0"     // 文字列リテラル
```

## ポインター
変数のアドレスを格納する為の型を「ポインタ型」という。

```cpp
int* pi;        // int型の変数のアドレスを格納できるポインタ型変数
```

変数のアドレスを取得するには、変数名の前に **アドレス演算子** を付ける。

```cpp
int i;
&i;     // 変数iのアドレスを int型へのポインタ変数へ代入
int* pi = &i;   // 変数 i のアドレスをint型へのポインタ型へ代入
```

アドレスを使って変数を操作するには、ポインタ変数の先頭に **間接参照演算子** を付ける。

```cpp
int i = 0;
int* pi = &i;   // pi は変数iのアドレス
*pi = 42;   // piが持つアドレスを使って変数 i を間接参照・代入
std::cout << i << std::endl;
```

### ポインタ渡し
引数で渡した変数を関数内部から変更することができる。

```cpp
void set42(int* pi) {
    *pi = 42;
}

int main() {
    int i = 0;
    set42(&i);
}
```

