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
