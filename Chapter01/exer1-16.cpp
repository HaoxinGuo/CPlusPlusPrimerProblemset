// C++primer课后练习题练习 1.16
#include<iostream>
using namespace std;
int main(){
	int sum = 0;
	int a;
	cout << "Please Enter The number and enter the CTRL+Z to quit" << endl;
	while(cin >> a)
		sum += a;
	cout<< "the sum of your enter is " << sum << endl;
}