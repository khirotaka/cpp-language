# リンケージ
C言語で書かれたプログラムを呼び出す時 or C言語からC++で書かれたプログラムを呼び出す時に必要。

- C++ から Cの関数を呼ぶ場合
- CからC++の関数を呼び場合

いずれもC++で設定してあげる必要がある。これは以下のようにする。


```cpp
// Cとリンクできる関数の宣言・定義
extern "C" ReturnType FuncName(...);


// Cとリンクできない関数の宣言・定義
extern "C++" ReturnType Function(...);
```


## 一括指定
```cpp
extern "C" {
    // ここに書かれたプロトタイプ宣言は Cリンケージ
    
    // extern "C++" {
    //  ここはC++
    // }
}
```

