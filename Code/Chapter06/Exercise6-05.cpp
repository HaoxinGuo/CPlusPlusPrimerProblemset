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
	cout<<"������һ������"<<endl;
	int val;
	cin>>val;
	cout<<"val"<<"�ľ���ֵ��"<<MyAbs1(val)<<endl;
	cout<<"val"<<"�ľ���ֵ��"<<MyAbs2(val)<<endl;
	return 0;
}