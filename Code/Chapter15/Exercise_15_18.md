练习15.18：假设给定了第543页和第544页的类，同时已知每个对象的类型如注释所示，判断下面的哪些赋值语句是合法的。解释那些不合法的语句为什么不被允许：

```c++
Base *p = &d1;	// d1的类型是Pub_Derv，合法
p = &d2;		// d2的类型是Priv_Derv，非法，非公有继承
p = &d3;		// d3的类型是Prot_Derv，非法，非公有继承
p = &dd1;		// dd1的类型是Derived_from_Public，合法
p = &dd2;		// dd2的类型是Derived_from_Private，非法，非公有继承
p = &dd3;		// dd3的类型是Derived_from_Protected，非法，非公有继承
```

-----------------

只有d1和dd1才能够赋值。因为只有d1和dd1类才是公有的继承类。