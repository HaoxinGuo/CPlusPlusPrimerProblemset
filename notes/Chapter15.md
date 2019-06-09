# 面向对象程序设计

面向对象程序设计基于三个基本概念：数据抽象、继承、动态绑定。

---------

## OOP概述

**面向对象程序设计(object-oriented programming)**的核心思想时数据抽象，继承和动态绑定。通过数据抽象我们可以将类的接口和实现分开，使用继承，我们可以定义相似的类型并对其相似关系建模；使用动态绑定，我们可以在一定程度上忽略相似类型的区别，而以统一的方式使用它们的对象。

**继承**

通过继承(inheritance)；联系在一起的类构成一种层次关系。通常在层次关系的根部有一个基类(base class)，其他类则间接或直接地从基类继承而来，这些继承而来的类称为派生类(derived class)。基类负责定义在层次关系中所有类共同拥有的成员，而每个派生类定义各自特有的成员。

```c++
class Quote{
public:
	std::string isbn() const;
	virtual double net_price(std::size_t n) const;
};

class Bulk_Quote:public Quote{
public:
	double net_price(std::size_t n) const override;
};
```

**动态绑定**

通过使用动态绑定(dynamic binding)，我们能用用一段代码分别处理Quote和Bulk_Quote的对象。

```c++
//计算并打印销售给定数量的某种书籍所得的费用
double print_total(ostream &os,const Quote &item,size_t n){
	//根据传入item的形参的对象调用Quote::net_price()
	//或者Bulk_Quote::net_price
	double ret = item.net_price(n);
	os<<"ISBN: "<<item.isbn()<< "# sold: "<<n<< "total due "<<ret<<endl;
	return ret;
}

//basic的类型时Quote,bulk的类型是Bulk_Quote

print_total(cout,basic,20);//调用Quote::net_price()

print_total(cout,bulk,20);//调用Bulk_Quote::net_price()
```

	当我们使用基类的引用或者指针调用一个虚函数时将发生动态绑定。

## 定义基类和派生类

### 定义基类

```c++
class Quote{
public:
	Quote() = default;
	Quote(std::string &book,double sales_price):bookNo(book),price(sales_price){}
	std::string isbn() const {return bookNo;};
	virtual double net_price(size_t n) const {return n*price;}
	virtual ~Quote()
private:
	std::string bookNo;
protected:
	double pricr = 0.0;
};
```

	通常，基类都应该定义一个虚析构函数，即使该函数在不执行任何实际操作也是如此。

**成员函数和继承**

成员函数如果没有被定义为虚函数，则其解析过程在发生编译时而不是运行时。

基类通过在其成员函数的声明语句之前加上关键词virtual使得该函数执行动态绑定。

**访问控制和继承**

派生类可以继承定义在基类的成员，但是派生类的成员函数不一定有权访问从基类继承而来的成员。派生类可以访问公有成员，而不能访问私有成员。不过，如果基类希望它的派生类有权访问该成员，同时禁止其他用户访问。我们用受保护的(protected)访问运算符说明这样的成员。

### 定义派生类

派生类必须使用类派生列表(class derivation list)明确指出它是从哪个基类继承而来的。

**派生类中的虚函数**

C++新标准允许派生类显式的注明它使用某个成员函数覆盖了它继承的虚函数。具体做法是在形参列表后面、或者在const成员函数的const关键词后面，或者在引用函数的引用限定符后面添加一个关键词override。

**派生类对象及派生类向基类的类型转换**

因为在派生类对象中含有基类对应的组成部分，所以我们能够把派生类的对象当成基类对象来使用，而且我们也能将基类的指针或引用绑定到派生类对象的基类部分上。

```c++
Quote item;		//基类对象
Bulk_Quote bulk;		//派生类对象
Quote *p = &item;		//p指向Quote对象
p = &bulk;		//p指向bulk的Quote部分
Quote &r = bulk;		r绑定到bulk的Quote部分
```

**派生类构造函数**

```c++
Bulk_Quote(const string &book,double p,size_t qty,double disc):
			Quote(book,p),min_qty(qty),discount(dis){}
```

	首先初始化基类的部分，然后按照声明的顺序依次初始化派生类的成员。

**派生类使用基类的成员**

派生类可以使用基类的公有和保护成员。

**继承与静态成员**

静态成员遵循通用的访问规则。

**被用作基类的类**

如果我们想将某个类作为基类，则该类必须已经定义而非仅仅声明：

```c++
class Quote;		//声明但未定义；
//错误：quote必须被定义
class Bulk_Quote:public Quote{...};
```

**防止继承的发生**

在类名后加一个final可以防止继承的发生。

```c++
class NoDerived final{};
```

### 类型转换与继承

可以将基类的指针或者引用绑定到派生类的对象上有一层极为重要的含义：当使用基类的引用或指针时，实际上我们不知道该引用（指针）所绑定对象的真实类型。该对象可能是基类的对象，也可能是派生类的对象。

**动态类型与静态类型**

我们必须把一个变量或者表达式的静态类型与该表达式表示对象的动态类型区分开来。表达式的静态类型在编译时总是已知的，它是变量声明时的类型或者表达式生成的类型；动态类型则是变量或者表达式表示的内存中的对象的类型。动态类型直到运行时才可知。

例如：当print_total调用net_price时`double ret = item.net_price(n);`

我们知道item的静态类型是Quote&，它的动态类型则依赖于item绑定的实参，动态类型直到运行时才可知。

**不存在从基类向派生类的隐式类型转换......**

因为一个基类的对象可能是派生类对象的一部分，也可能不是，所以不存在从基类到派生类的自动类型转换。

```c++
Quote base;
Bulk_Quote* bulkp = &base;		//错误：不能将基类转换成派生类
Bulk_Quote& bulkref = base;		//错误：不能将基类转换成派生类
Bulk_Quote bulk;
Quote *itemp = &bulk;		//正确：动态类型是Bulk_Quote
Bulk_Quote *bulkp = itemp;		//错误：不能将基类转换成派生类
```

**......在对象之间不存在类型转换**

	当我们用一个派生类为一个基类对象赋值时，只有该派生类对象中的基类部分会被拷贝，移动和赋值，它的派生类部分会被忽略掉。



















