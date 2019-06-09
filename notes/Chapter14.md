# 重载运算和类型转换

## 基本概念

重载运算符是具有特殊名字的函数：他们的名字由关键字operator和其后要定义的运算符号组成。重载运算符也包含返回类型，参数列表以及函数体。

	当一个运算符是成员函数时，this绑定到左侧运算对象。成员运算符函数的（显式）参数数量比运算对象的数量少一个。

对于一个运算符函数来是哦，它或者是类的成员，或者至少含有一个类型的参数：

```c++
//错误，不能为int重定义内置的运算符
int operator+(int,int);
```

不能被重载的运算符： .* :: . ? ：

**直接调用一个重载的运算符函数**

调用方法如下：

```c++
//一个非成员运算符的等价调用
data1+data2;//普通的表达式
operator+(data1,data2);//等价的函数调用
data1 += data2;//基于调用的表达式
data1.operator+=(data2);//对成员运算符函数的等价调用
```

将this绑定到data1的位置，将data2作为实参传入函数。

**某些运算符不应该被重载**

	通常情况下不应该重载逗号，取地址，逻辑与和逻辑或运算符。

**使用与内置类型一致的含义**

**选择作为成员或者非成员函数**

有的运算符必须作为成员，另一些情况下，运算符作为非成员更好：

1. 赋值（=）、下标（[]）、调用（()）和成员访问箭头（->）运算符必须作为成员；

2. 复合赋值运算符一般来说应该是成员，但并非必须，这一点与赋值略有不同；

3. 递增、递减和解引用运算符，一般应该是成员；

4. 具有对称性的运算符可能转换任意一端的运算对象，例如算术、相等性、关系和位运算符等，因此它们通常应该时普通的非成员函数。

```c++
string s = "world";
string t = s + "!";//正确，我们能把一个const char*加到一个string中等价于s.operator+("!")
string u = "Hi" + s;//错误，等价于："Hi".operator+(s),hi的类型是const char* ，这是一种内置类型，没有成员函数
```

## 输入和输出运算符

### 重载输出运算符<<

第一个形参通常是一个非常量的ostream对象的引用，之所以ostream是非常量是因为向流写入内容会改变其状态，而引用该形参是因为我们没法直接复制一个ostream对象。

第二个形参通常是一个常量的引用，该常量是我们要输出的类类型。

为了与其他输出运算符保持一致，operator<<通常返回它的ostream形参。例如：

```c++
class Salas_data{
friend std::ostream& operator<<(ostream&, const Salas_data&);
friend std::ostream& operator>>(istream&, const Salas_data&);
};
```

	通常，输出运算符不应该打印换行符，主要负责输出打印的对象而非格式。

**输出输出运算符必须是非成员函数**

### 重载输入运算符>>

通常情况下，输入运算符的第一个实参为将要读取的流的引用，第二个形参为将要读入到的（非常量）对象的引用。该运算符会返回某个流的引用。

	输入运算符必须处理输入失败的问题，而输出运算符不需要。

## 算术和关系运算符

通常我们把算术和关系运算符作为非成员函数以允许对左侧和右侧的运算对象进行转换。形参都是常量的引用。

```c++
Salas_data operator+(const Salas_data &lhs,const Salas_data &rhs){
	Salas_data sum = lhs;
	sum += rhs;
	return sum;
}
```

	如果类同时定义了算术运算符和相关的复合赋值运算符，则通常情况下应该使用复合赋值运算符来实现。

### 相等运算符

```c++
bool operator==(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() == rhs.isbn() &&
	       lhs.units_sold == rhs.units_sold &&
	       lhs.revenue == rhs.revenue;
}

bool operator!=(const Sales_data &lhs, const Sales_data &rhs)
{
	return !(lhs == rhs);
}
```

### 关系运算符

如果一个类不存在一种逻辑可靠的<定义，这个类不定义<运算符也许更好。

### 赋值运算符

之前介绍了拷贝赋值和移动赋值运算符，它们可以把类的一个对象赋值给类的另一个对象。此外，类还可以定义其他赋值运算符以使用别的类型作为右侧运算对象。

比如：

```c++
vector<string> v;
v = {"a", "b", "c"};
```

```c++
class StrVec {
public:
	StrVec& operator=(std::initializer_list<std::string>)
	{
		// ...
	}
};
```

	赋值运算符必须为成员函数。

### 复合赋值运算符 

	赋值运算符必须为成员函数，复合赋值运算符通常情况下也应该这样做。这两类运算符都应该返回左侧运算对象的引用。

```c++
// 作为成员的二元运算符：左侧运算对象绑定到隐式的this指针
Sales_data& Sales_data::operator+=(const Sales_data &rhs)
{
	units_sold += rhs.units_sold;
	revenue += rhs.revenue;
	return *this;
}
```

### 下标运算符

表示容器的类通常可以通过元素在容器中的位置访问元素，这些类一般会定义下标运算符operator[]。

	下标运算符必须是成员函数。

为了与下标的原始定义兼容，下标运算符通常以所访问元素的引用作为返回值，这样做的好处是下标可以出现在赋值运算符的任意一端。最好同时定义下标运算符的常量版本和非常量版本，当用作于一个常量对象时，下标运算符返回常量引用以确保我们不会给返回的对象赋值。

```c++
class StrVec {
public:
	std::string& operator[](std::size_t n) { return elements[n]; }

	const std::string& operator[](std::size_t n) const { return elements[n]; }

private:
	std::string *elements;	// 指向数组首元素的指针
};
```

## 递增递减运算符

在迭代器类中通常会实现递增运算符++和递减运算符--，这两种运算符使得类可以在元素的序列中前后移动。

对于内置类型来说，递增和递减运算符既有前置版本也有后置版本。同样，我们也应该为类定义两个版本的递增和递减运算符。

```c++
class StrBlobPtr {
public:
	StrBlobPtr& operator++();		// 前置运算符
	StrBlobPtr& operator--();
};
```

```c++
//前置版本：返回递增递减对象的引用
StrBlobPtr& StrBlobPtr::operator++(){
//如果curr已经指向了容器的尾后位置，则无法递增它
	check(curr, "increment past end of StrBlobPtr ")
	++curr;	//将curr在当前状态下向前移动一个元素
	return *this;
}

StrBlobPtr& StrBlobPtr::operator--(){
	//如果curr是0，则继续递减它将产生一个无效下标
	--curr;		//将curr在当前状态下向后移动一个元素
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}
```

**区分前置和后置运算符**

后置版本接受一个额外的（不被使用的）int类型的形参，这个形参的唯一作用就是区分前置版本和后置版本的函数，而不是真的要在实现后置版本时参与运算。

```c++
class StrBlobPtr {
public:
	StrBlobPtr operator++(int);		// 后置运算符
	StrBlobPtr operator--(int);
};
```

!!!note
	为了与内置版本保持一致，后置运算符应该返回对象的原值，返回的形式是一个值而非引用。

```c++
//后置版本：递增递减对象的值但是返回原值
StrBlobPtr StrBlobPtr::operator++(int){
	//此处无须检查有效性，调用前置递增运算符时才需要检查
	StrBlobPtr ret = *this;//记录当前的值
	++*this;//向前移动一个元素，前置++需要检查递增的有效性
	return ret;//返回之前记录的状态
}

StrBlobPtr StrBlobPtr::operator--(int){
	//此处无须检查有效性，调用前置递减运算符时才需要检查
	StrBlobPtr ret = *this	//记录当前的值
	--*this //向后移动一个元素，前置--需要检查递减的有效性
	return ret;
}
```

**显式的调用后置运算符**

```c++
StrBlobPtr p(a1);//p指向a1中的vector
p.operator++(0);//调用后置版本的operator++
p.operator++();//调用前置版本的operator++
```

## 成员访问运算符

在迭代器类及智能指针类中常常用到解引用运算符和箭头运算符。

```c++
class StrBlobPtr {
public:
	std::string& operator*() const;
	{
		auto p = check(curr,"dereference past end");
		return (*p)[curr];
	}
	std::string* operator->() const
	{
		// 将实际工作委托给解引用运算符
		return & this->operator*();
	}
};
```

**对箭头运算符返回值的限定**

对于形如point->mem的表达式来说，point必须是指向类对象的指针或者是一个重载了operator->类的对象。根据point类型的不同，point->分别等价于：

```c++
(*point).mem;		//point是一个内置的指针类型
point.operator()->mem;		//point是一个类对象
```

除此之外，代码都将发生错误。

## 函数调用运算符

如果类重载了函数调用运算符，则我们可以像使用函数一样使用该类的对象。因为这样的类同时也能存储状态，所以与普通函数相比它们更灵活。

```c++
struct absInt {
	int operator()(int val) const {
		return val < 0 ? -val : val;
	}
};
```

这个类只定义了一种操作：函数调用运算符，它负责接受一个int类型的实参，然后返回该实参的绝对值。

使用调用运算符的方式是令一个absInt对象作用于一个实参列表，这一过程看起来非常像调用函数的过程：

```c++
int i = -42;
absInt absObj;
int ui = absObj(i);		// 将i传递给absObj.operator()
```

函数调用运算符必须是成员函数。一个类可以定义多个不同版本的调用运算符，相互之间应该在参数数量或类型上有所区别。

如果类定义了调用运算符，则该类的对象称作函数对象（function object）。因为可以调用这种对象，所以我们说这些对象的行为像函数一样。




### lambda是函数对象

当我们编写了一个lambda后，编译器将该表达式翻译成一个未命名类的未命名对象。在lambda表达式产生的类中含有一个重载的函数调用运算符，默认情况下，它是一个const成员函数。

当一个lambda表达式通过引用捕获变量时，将由程序负责确保lambda执行时引用所引用的对象确实存在。因此，编译器可以直接使用该引用而无须在lambda产生的类中将其存储为数据成员。

通过值捕获的变量被拷贝到lambda中。因此，这种lambda产生的类必须为每个值捕获的变量建立对应的数据成员，同时创建构造函数，令其使用捕获的变量的值来初始化数据成员。

### 标准库定义的函数对象

标准库定义了一组表示算术运算符、关系运算符和逻辑运算符的类，每个类分别定义了一个执行命名操作的调用运算符。例如，plus类定义了一个函数调用运算符用于对一对运算对象执行+操作。

这些类都被定义成模板的形式，我们可以为其指定具体的应用类型，这里的类型即调用运算符的形参类型。例如，`plus<string>`令string的加法运算符作用于string对象。

```c++
plus<int> intAdd;			// 可执行int加法的函数对象
int sum = intAdd(10, 20);	// 使用intAdd::operator(int, int)求10和20的和
```

**在算法中使用标准库函数对象**

表示运算符的函数对象类常用来替换算法中的默认运算符。比如，默认情况下排序算法使用operator<将序列按照升序排列。如果要执行降序排列的话，我们可以传入一个greater类型的对象。

```c++
// 传入一个临时的函数对象用于执行两个string对象的>比较运算
sort(svec.begin(), svec.end(), greater<string>());
```

### 可调用对象与function

C++语言中有几种可调用的对象：函数、函数指针、lambda表达式、bind创建的对象以及重载了函数调用运算符的类。

和其他对象一样，可调用对象也有类型。lambda有它自己唯一的未命名的类类型；函数及函数指针的类型由其返回值和实参类型决定。

然而，两个不同类型的可调用对象却可能共享同一种调用形式（call signature）。调用形式指明了调用返回的类型以及传递给调用的实参类型。一种调用形式对应一个函数类型，例如：

```c++
int(int, int)
```
**标准库function函数**

function是一个模板，当创建一个具体的function类型时我们必须提供额外的信息，此额外信息是指该function类型能够表示的对象的调用形式：

```c++
function<int(int, int)>
```

这里声明的function类型，表示接受两个int、返回一个int的可调用对象：

```c++
function<int(int, int)> f1 = add;			// 函数指针
function<int(int, int)> f2 = divide();		// 函数对象类的对象
function<int(int, int)> f3 = [](int i, int j) { return i * j; };	// lambda

cout << f1(4, 2) << endl;
cout << f2(4, 2) << endl;
cout << f3(4, 2) << endl;
```

## 重载、类型转换与运算符

在263页中我们看到由一个实参调用的非显示构造函数定义了一种隐式的类型转换，这种构造函数将实参类型的对象转换成类类型。我们同样能定义对于类类型的类型转换，通过定义类型转换运算符可以做到这一点。

转换构造函数和类型转换运算符共同定义了**类类型转换（class-type conversions）**。

### 类型转换运算符

**类型转换运算符（conversion  operator）**是类的一种特殊成员函数，它负责将一个类类型的值转换成其他类型。其一般形式如下：

```c++
operator type() const;
```

其中type表示某种类型。类型转换运算符可以面向任意类型（除了void之外）进行定义，只要该类型能作为函数的返回类型，因此我们不允许转换成数组或者函数类型，但允许转换成指针或者引用类型。

	类型转换运算符既没有显式的返回类型，也没有形参，而且必须定义成类的成员函数。类型转换运算符通常不应该改变待转换对象的内容，因此，一般被定义成const成员。

**定义含有类型转换运算符的类**

举个例子，我们定义一个比较简单的类，令其表示0到255之间的一个整数：

```c++
class SmallInt {
public:
	SmallInt(int i = 0) : val(i)
	{
		if (i < 0 || i > 255)
			throw std::out_of_range("Bad SmallInt value");
	}

	operator int() const { return val; }
private:
	std::size_t val;
};
```

SmallInt类的构造函数将算数类型的值转换成SmallInt对象，而类型转换运算符将SmallInt对象转换成int：

```c++
SmallInt si;
si = 4;			// 4 -> SmallInt, 然后调用赋值运算符
si + 3;			// si -> int，然后执行整数的加法
```

**类型转换运算符可能产生意外结果**

在实践中，类很少提供类型转换运算符。但有一种例外：对于类来说，定义向bool的类型转换还是比较普遍的现象，但这会遇到一个问题：因为bool是一种算术类型，所以类类型的对象转换成bool后就能被用在任何需要算术类型的上下文中（这不是期望的）。

**显式的类型转换运算符**

为了防止上述异常情况的发生，C++新标准引入了显式的类型转换运算符（explicit conversion operator）：

```c++
class SmallInt {
public:
	// 编译器不会自动执行这一类型转换
	explicit operator int() const { return val; }
};
```

编译器不会将一个显式的类型转换运算符用于隐式类型转换：

```c++
SmallInt si = 3;			// 正确：SmallInt的构造函数不是显式的
si + 3;						// 错误：此处需要隐式的类型转换，但类的运算符是显式的
static_cast<int>(si) + 3;	// 正确：显式地请求类型转换
```

但，如果表达式被用作条件，则编译器会将显示的类型转换自动应用于它。


	向bool的类型转换通常用在条件部分，因此operator bool一般定义成explicit的。

### 避免有二义性的类型转换

	通常情况下，不要为类定义相同的类型转换，也不要在类中定义两个及两个以上转换源或转换目标是算术类型的转换。

**实参匹配和相同的类型转换**



	我们无法通过强制类型转换来解决二义性问题，因为强制类型转换也面临二义性问题。

### 函数匹配和重载运算符










