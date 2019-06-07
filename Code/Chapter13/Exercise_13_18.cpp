// 练习13.18：定义一个Employee类，它包含雇员的姓名和唯一的雇员编号。为这个类
// 定义默认构造函数，以及接受一个表示雇员姓名的string的构造函数。每个构造函
// 数应该通过递增一个static数据成员来生成一个唯一的证号。

// 练习13.17：分别编写前三题所描述的numbered和f， 验证你是否正确预测了输出结果。

#include <iostream>
#include<string>
using namespace std;

int gen_number()
{
	static int n = 0;
	return ++n;
}

class Employee {
public:
	Employee() :Id(gen_number()) {};
	Employee(const string name) :Name(name), Id(gen_number()) {};
	int Get_Id() const { return Id; };
	void Print() const { cout << "id: " << Id << endl; }
private:
	//Employee(const Employee&) = delete;
	//Employee& operator=(const Employee&) = delete;
	string Name;
	int Id;
};


/*
void f(Employee s) {
	cout << s.Get_Id() << endl;
}
*/


int main()
{
	Employee a;
	a.Print();
	char ch;
	cin >> ch;
	return 0;
}