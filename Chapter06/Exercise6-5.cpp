#include<iostream>
#include<cmath>
using namespace std;

double MyAbs1(double val){
	return (val>0)?val:(-val);
}

double MyAbs2(double val){
	return abs(val);
}

int main(){
	cout<<"请输入一个数："<<endl;
	int val;
	cin>>val;
	cout<<"val"<<"的绝对值是"<<MyAbs1(val)<<endl;
	cout<<"val"<<"的绝对值是"<<MyAbs2(val)<<endl;
	return 0;
}