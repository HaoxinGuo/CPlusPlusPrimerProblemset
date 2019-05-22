// C++primer课后练习题练习 2.21
// p1 *p1 的区别
#include<iostream>
#include<typeinfo>
using namespace std;
int main(){
	const int i=42;
	auto j=i;
	const auto &k=i;
	auto *p = &i;
	const auto j2 = i,&k2 = i;
	cout<<typeid(i).name()<<endl;
	cout<<typeid(j).name()<<endl;
	cout<<typeid(k).name()<<endl;
	cout<<typeid(p).name()<<endl;
	cout<<typeid(j2).name()<<endl;
	cout<<typeid(k2).name()<<endl;
	return 0;
}