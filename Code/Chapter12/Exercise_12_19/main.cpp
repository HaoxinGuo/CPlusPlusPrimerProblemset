#include<iostream>
#include"Strblob.h"
#include"StrblobPtr.h"

using namespace std;
int main() {
	Strblob b1;
	{
		Strblob b2 = { "a","an","the" };
		b1 = b2;
		b2.push_back("about");
		cout << b2.size() << endl;
	}
	cout << b1.size() << endl;
	cout << b1.front() << " " << b1.back() << endl;
	const Strblob b3 = b1;
	cout << b3.front() << " " << b3.back() << endl;
	char ch;
	cin >> ch;
	return 0;
}