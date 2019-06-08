练习13.54：如果我们为HasPtr定义了移动赋值运算符，但未改变拷贝并交换运算符，会发生什么？编写代码验证你的答案。

---

`error: ambiguous overload for ‘operator=’ (operand types are ‘HasPtr’ and ‘std::remove_reference<HasPtr&>::type {aka HasPtr}’)`

因为对于`hp=std::move(hp2)`这样的赋值语句来说，两个运算符匹配的一样好，从而产生的二义性。

