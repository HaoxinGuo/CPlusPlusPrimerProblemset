// 练习13.19：你的Employee类需要定义它自己的拷贝控制成员吗？如果需要，为什么？
// 如果不需要，为什么？实现你认为Employee需要的拷贝控制成员。

// 我认为不需要，认为一个员工实体应该是唯一的。

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
	Employee(const Employee&) = delete;
	Employee& operator=(const Employee&) = delete;
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