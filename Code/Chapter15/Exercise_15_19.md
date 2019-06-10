练习15.19：假设543页和544页的每个类都有如下形式的成员函数u：

```c++
void memfcn(Base &b) { b = *this; }
```

对于每个类，分别判断上面的函数是否合法。

Base: 合法

Sneaky: 合法，但只会拷贝其基类部分

Pal: 合法

Pub_Derv: 合法

Priv_Derv: 合法

Derived_from_Public: 合法

Derived_from_Private: 合法
