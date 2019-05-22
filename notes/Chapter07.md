# 第七章 类
类的基本思想是**数据抽象**(data abstraction)和**封装**(encapsulation)。  
数据抽象就是**接口(interface)与实现(implementation)分离**的技术。  
接口就是暴露给用户的操作，比如公有的成员函数。  
实现就是数据成员、接口的实现、私有的成员函数。  
通过**抽象数据类型(abstract data type)**，来实现数据抽象和封装。  
## 定义抽象数据类型  
封装就是隐藏，抽象数据类型隐藏了自己的成员变量，外部只能使用其接口来间接访问其成员。  
**定义成员函数**  
类内的所有成员必须声明在类的内部。  
类的成员函数可以定义在类的内部，也可以定义在类的外部。  
	定义在类内部的函数是隐式的inline函数。  
**引入this**  
当调用一个成员函数时，实际上是替某个对象调用它。  
成员函数通过名为**this**的隐式参数来访问此对象。this指向了此对象的地址。  
在成员函数内部，可以省略this来访问成员。  
this是一个常量指针，不能够修改其值。  
当成员函数中调用另一个成员函数时，将隐式传递this指针。  
```
std::string isbn() const {return this->bookNo;}
```
**引入const成员函数**  
参数列表之后，添加const关键字，表明传入的this指针是一个指向常量对象的指针。故此成员函数内，不能修改成员变量的内容。  
const对象只能调用const版本的成员函数（因此如果函数不修改成员变量，那么为了提高灵活性，应该把函数声明成const版本的）。  
C++语言的做法是允许把const关键字放在成员函数的参数列表之后，此时，紧跟在参数列表后面的const表示this是一个指向常量的指针。像这样使用const的成员函数被称作常量成员函数（const member function）。  
	常量对象，以及常量对象的引用或指针都只能调用常量成员函数。  
**类作用域和成员函数**  
类本身就是一个作用域。  
成员函数的定义必须包含其所属的类名（使用作用域运算符）。  
如果成员函数声明为const版本的，其定义时，也要在参数列表后加const。  
成员函数体可以随意使用类中的成员，无须在意成员出现的顺序，这是因为编译器分两步处理类：首先编译成员的声明，然后才轮到成员函数体。  
**定义一个返回this对象的函数**  
可以使用如下语句返回this对象：  
```c++
return *this;
```  
返回类型使用引用类型，表明返回的就是this所指的对象。  
一般来说，当我们定义的函数类似于某个内置运算符时，应该令函数的行为尽量模仿这个运算符。比如说内置的赋值运算符把它的左侧运算对象当成左值返回，这种情况下，函数就可以返回this对象的引用。  
### 定义类相关的非成员函数  
有些函数也提供了操作类对象的方法，但他们不属于类的成员函数。  
可以把这些函数放到类的头文件中声明。这些函数也可以看成是类的接口。  
有可能会把这些函数声明称友元，从而方便它们直接操作成员变量。  
### 构造函数  
类通过一个或几个特殊的成员函数初始化其成员变量，这些函数叫**构造函数（constructor）**。  
每当类对象被创建，构造函数就会被执行。  
构造函数名和类名一致，无返回类型，可能有多个（参数个数差异），不能是const的。  
对于const对象，构造函数执行完毕后，它才获得const属性。  
**合成的默认构造函数**  
如果对象没有初始值，它将执行默认初始化。  
类通过**默认构造函数(default constructor)**来执行默认初始化。如果没有显示定义过构造函数，编译器就会自动生成一个，叫做合成的默认构造函数。  
合成的默认构造函数根据如下规则初始化类成员：  
- 如果存在类内初始值，使用它来初始化成员  
- 否则，对成员执行默认初始化  
**某些类不能依赖合成的默认构造函数**  
所谓不能依赖，就是不可以让编译器生成默认构造函数，要自己定义一个。其原因可能是：  
- 如果定义了自己的构造函数，那么编译器就不会生成默认的构造函数，此类就没有了默认构造函数。  
- 默认构造函数可能执行的是错误的操作，比如内置类型若没有类内初始值，则进行默认初始化，其值未定义。  
- 有时候，编译器无法生成默认构造函数，比如类成员中有类，而此类有可能没有默认构造函数。  
**=default的含义**  
C++11中，使用这种语句来让编译器生成一个默认构造函数：  
```c++
SalesData() = default;
```  
	这种情况下，应当对内置类型的数据成员提供类内初始值，否则应当使用构造函数初始值列表形式的默认构造函数。  
**构造函数初始值列表**  
```c++
Sales_data(const std::string &s):
									bookNo(s){}
Sales_data(const std::string &s,unsigned n,double p):
														bookNo(s),units_sold(n),revenue(p*n){}
```
参数列表后，函数体前的一部分内容叫构造函数初始值列表（constructor initialize list）。  
它负责为对象的成员变量赋初值。  
如果成员不在初始化列表中，它用类内初始值初始化（如果存在），否则执行默认初始化。  
	构造函数不应该轻易覆盖掉类内的初始值，除非新赋的值与原值不同。如果你不能使用类内初始值，则所有构造函数都应该显式地初始化每个内置类型的成员。
### 拷贝、赋值和析构  
拷贝构造函数，当初始化变量时以值传递或函数返回一个对象时，会发生拷贝。  
赋值运算，当使用了赋值运算符时，会发生对象的赋值操作。  
析构函数，当一个变量不在存在时，会执行析构。  
这些操作如果不显示定义，编译器就会合成一个，合成的拷贝赋值版本只是做了浅拷贝操作。  
**某些类不能依赖合成的版本**  
如果类中有成员绑定了外部的对象（比如动态内存），那么就不可依赖合成的版本。  
可使用容器管理必要的存储空间，当发生拷贝等操作时，容器也会执行正确的拷贝。  