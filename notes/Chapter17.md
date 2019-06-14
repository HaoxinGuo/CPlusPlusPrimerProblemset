# 标准库特殊设施

## tuple类型

tuple是类似pair的模板。每个pair的成员类型都不相同，但是每个pair都恰好有两个成员。不同tuple类型的成员类型也不相同，但是每个tuple可以有任意数量的成员。每个确定的tuple类型的成员数目是固定的，但一个tuple类型的成员数目可以与另一个tuple类型不同。

```c++
tuple支持的操作
tuple<T1,T2,...,Tn> t;
tuple<T1,T2,...,Tn> t(v1,v2,v3,v4,...,vn);
make_tuple(v1,v2,...,vn);
t1==t2;
t1 relop t2;
get<i>(t);
```

### 定义和初始化tuple

当我们定义一个tuple时，需要指出每个成员的类型：

```c++
tuple<size_t,size_t,size_t> threeD;//三个成员都设置为0
tuple<string,vector<double>,int,list<int>) someVal("contents",{3.14,2.718},42,{0,1,2,3,4,5})
```

**访问tuple的成员**

要访问一个tuple的成员，就要使用一个名为get的标准函数模板。


























