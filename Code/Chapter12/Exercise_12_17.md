练习12.7：下面的unique_ptr声明中，哪些是合法的，哪些可能导致后续的程序错误？解释每个错误的问题在哪里。

```
int ix = 1024, *pi = &ix, *pi2 = new int(1024);
typedef unique_ptr<int> IntP;
```

(a) IntP p0(ix); // 错误，unique_ptr只能指向一块动态内存

(b) IntP p1(pi); // 合法，可以用一个int*来初始化IntP，但此程序逻辑上是错误的。它用一个普通int变量的地址初始化p1，p1销毁时会释放此内存，其行为是未定义的。

(c) IntP p2(pi2); // 正确，但是pi2不能再手动释放

(d) IntP p3(&ix); // 合法，但是存在与（b）同样的问题。

(e) IntP p4(new int(2048)); // 正确

(f) IntP p5(p2.get()); // 合法，使用p2管理的对象的地址来初始化p5，造成两个unique_str指向同一个相同的内存地址。当其中一个unique_str被销毁时，该内存被释放，另一个unique_str变为空悬指针。
