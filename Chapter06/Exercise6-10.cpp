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
	cout<<"��������������"<<endl;
	int val1,val2;
	cin>>val1>>val2;
	cout<<"δ����ǰ"<<val1<<"  "<<val2<<endl;
	Myswap1(&val1,&val2);
	cout<<"������"<<val1<<"  "<<val2<<endl;
	Myswap2(val1,val2);
	cout<<"�ٴν�����"<<val1<<"  "<<val2<<endl;
	return 0;
}