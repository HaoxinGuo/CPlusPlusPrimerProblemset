/*
 * 练习14.5：在7.5.1节的练习7.40（第261页）中，编写了下列类中某一个的框架，
 * 请问在这个类中应该定义重载的运算符吗？如果是，请写出来。
 */


/*
 * 练习7.40：从下面的抽象概念中选择一个（或者你自己指定一个），思考这样的类需要
 * 哪些数据成员，提供一组合理的构造函数并阐明这样做的原因。
 */

/*
 * 比如选择Date，这里可以定义输入输出运算符
 */

#include <iostream>
#include <string>

using std::cout;
using std::endl;
using std::cin;

class Date
{
	friend std::ostream& operator<<(std::ostream &os, const Date &rhs);
	friend std::istream& operator>>(std::istream &is, Date &rhs);

public:
	Date() = default;
	Date(unsigned int  y,unsigned int  m,unsigned int d) : year(y),month(m),day(d) {}
	Date(std::istream &is) { is >> year >> month >> day; }

	void print() { std::cout << year << " " << month << " " << day << std::endl; }

private:
	unsigned int year = 0;
	unsigned int month = 0;
	unsigned int day = 0;

};

std::ostream& operator<<(std::ostream &os, const Date &rhs)
{
	os << rhs.year << " " << rhs.month << " " << rhs.day;
	return os;
}

std::istream& operator>>(std::istream &is, Date &rhs)
{
	is >> rhs.year >> rhs.month>> rhs.day;
	if (!is)
		rhs = Date();
	return is;
}

int main()
{
	Date b1; // 默认构造函数，使用类内初始值初始化成员
	cout << b1 << endl;

	Date b2(2019,6,9); // 需要使用一个构造函数来初始化所有成员
	cout << b2 << endl;

	Date b3;
	cin >> b3;
	cout << b3 << endl;

	return 0;
}
