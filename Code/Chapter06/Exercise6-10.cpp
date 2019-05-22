#include<iostream>

using namespace std;

void Myswap1(int *p,int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}

void Myswap2(int &p,int &q){
	int temp = p;
	p = q;
	q = temp;
}


int main(){
	cout<<"请输入两个数："<<endl;
	int val1,val2;
	cin>>val1>>val2;
	cout<<"未交换前"<<val1<<"  "<<val2<<endl;
	Myswap1(&val1,&val2);
	cout<<"交换后"<<val1<<"  "<<val2<<endl;
	Myswap2(val1,val2);
	cout<<"再次交换后"<<val1<<"  "<<val2<<endl;
	return 0;
}