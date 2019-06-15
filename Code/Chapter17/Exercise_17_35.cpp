// 练习17.35：修改第670页中的程序，打印2的平方根，但这次打印十六进制数字的大写形式。

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

void func()
{
	cout << hexfloat << uppercase << sqrt(2.0) << endl;
}

int main()
{
	func();

	return 0;
}
