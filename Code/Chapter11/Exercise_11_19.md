练习11.19：定义一个变量，通过对11.2.2节（第378页）中的名为bookstore的multiset调用begin()来初始化这个变量。写出变量的类型，不要使用auto或decltype。

---

`multiset<Sales_data, compare_func>::iterator it = bookstore.begin();`
