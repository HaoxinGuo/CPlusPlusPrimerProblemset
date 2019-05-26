练习11.16：使用一个map迭代器编写一个表达式，将一个值赋予一个元素。

---

```
map<int,int> m;
auto it = m.begin();
it->second = 0;
```
