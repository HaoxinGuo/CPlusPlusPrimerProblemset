// 练习17.36：修改上一题中的程序，打印不同的浮点数，使它们排成一列。

// 练习17.35：修改第670页中的程序，打印2的平方根，但这次打印十六进制数字的大写形式。

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void func(float v)
{
	cout << hexfloat << uppercase << v << endl;
}

int main()
{
	func(3.14);
	func(sqrt(2));

	return 0;
}
