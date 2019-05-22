# try语句块
try语句块的通用语法形式是：  
```c++
try {
    program-statements
} catch (exception-declaration) {
    handler-statements
} // ...
```  
当选中了某个catch子句处理异常之后，执行与之对应的块。catch一旦完成，程序跳转到try语句块最后一个catch子句之后的那条语句继续执行。  
try语句块内声明的变量在catch子句内无法访问。  
一个简要的例子：  
```c++
while (cin >> item1 >> item2) {
    try {
        // ... 可能抛出一个异常的代码
    } catch (runtime_error err) {
        cout << err.what() << "\nTry Again? Enter y or n" << endl;
        char c;
        cin >> c;
        if (!cin || c == 'n')
            break; // 跳出while循环
    }
}
```  
# throw表达式
抛出异常的一个例子是：  
```c++
throw runtime_error("Data must refer to same ISBN");
```  
该异常是类型runtime_error的对象。抛出异常将终止当前的函数，并把控制权转移给能处理该异常的代码。  
- **throw 表达式（throw expression）**，异常检测部分使用throw表达式来表示它遇到了无法处理的问题。我们说throw**引发（raise）**了异常。  
- **try语句块（try block）**，异常处理部分使用try语句块处理异常。try语句块以关键字try开始，并以一个或多个**catch子句（catch clause）**结束。try语句块中代码抛出的异常通常会被某个catch子句处理。  
- 一套**异常类（exception class）**，用于在throw表达式和相关的catch子句之间传递异常的具体信息。  
# 简单语句
C++语言中的大多数语句都以分号结束，一个表达式，比如ival+5，末尾加上分号就变成了**表达式语句**(expression statement)，表达式语句的作用是执行表达式并丢弃掉求值结果：
```c++
ival + 5;    // 无意义的表达式语句
cout << ival;// 有意义的表达式语句
```  
**空语句**  
最简单的语句是**空语句**（null statement），它只有一个分号： 
```c++
; // 空语句
```  
如果在程序的某个地方，语法上需要一条语句但是逻辑上不需要，此时应该使用空语句。  
**复合语句（块）**  
复合语句（compound statement）是指用花括号括起来的语句和声明的序列，复合语句也被称作**块**（block）。一个块就是一个作用域。  
如果在程序的某个地方，语法上需要一条语句，但是逻辑上需要多条语句，则应该使用复合语句。  
所谓空块，是指内部没有任何语句的一对花括号。空块的作用等价于空语句：  
```c++
while (cin >> s && s != sought)
{}  // 空块
```  
# 语句作用域
可以在if、switch、while和for语句的控制结构内定义变量。定义在控制结构当中的变量只在相应语句的内部可见，一旦语句结束，变量也就超出其作用范围了：  
```c++
while (int i = get_num()) // 每次迭代时创建并初始化
    cout << i << endl;
i = 0;    // 错误，在循环外部无法访问
```  
# 条件语句
C++语言提供了两种按条件执行的语句。一种是if语句，它根据条件决定控制流；另一种是switch语句，它计算一个整型表达式的值，然后根据这个值从几条执行路径中选择一条。  
## if语句
if语句的作用是：判断一个指定的条件是否为真，根据判断结果决定是否执行另外一条语句。  
## switch语句
switch语句提供了一条便利的途径使得我们能够在若干固定选项中做出选择。  
# 迭代语句
迭代语句通常称之为循环，它重复执行操作直到满足某个条件才停下来。while和for语句在执行循环体之前检查条件，do while语句先执行循环体，然后再检查条件。  
## while语句
语法格式是：  
```c++
while (condition)
    statement
```  
只要condition的求值结果为真就一直执行statement。如果condition第一次求值就是false，statement一次都不执行。  
while的条件部分可以是一个表达式或者是一个带初始化的变量声明。  
**使用while循环**  
当不确定到底要迭代多少次时，使用while循环比较合适。还有一种情况也应该使用while循环，这就是我们想在循环结束后访问循环控制变量。  
## 传统的for语句  
for语句的语法形式是  
```c++
for (init-statement: condition; expression)
    statement
```
## 范围for语句
C++11新标准引入了一种更简单的for语句，这种语句可以遍历容器或其他序列的所有元素。**范围for语句**（range for statement）的语法形式是：
```c++
for (declaration : expression)
    statement
```
expression必须是一个序列，比如用花括号括起来的初始值列表、数组、或者vector或string等类型的对象，这些类型的共同特点是拥有能返回迭代器的begin和end成员。  
declaration定义一个变量，序列中的每个元素都能转换成该变量的类型。  
每次迭代都会重新定义循环控制变量，并将其初始化成序列中的下一个值，之后才会执行statement。  
在范围for语句中，预存了end()的值。一旦在序列中添加（删除）元素，end函数的值就可能变得无效了。因此不能通过范围for语句增加vector对象的元素。  
## do while语句
do while语句和while语句非常相似，唯一的区别是，do while语句先执行循环体后检查条件。不管条件的值如何，我们都至少会执行一次循环。do while语句的语法形式如下：  
```c++
do
    statement
while (condition);
```
# 跳转语句  
跳转语句中断当前的执行过程。C++语言提供了4种跳转语句：break, continue, goto和return。本章介绍前三种，return在第六章介绍（p199页）。  
## break语句
break语句负责终止离它最近的while, do while, for或switch语句，并从这些语句之后的第一条语句开始执行。
## continue语句
continue语句终止最近的循环中的当前迭代并立即开始下一次迭代。continue语句只能出现在for, while和do while循环的内部。  
## goto语句  
goto语句（goto statement）的作用是从goto语句无条件跳转到同一函数内的另一条语句。  


































