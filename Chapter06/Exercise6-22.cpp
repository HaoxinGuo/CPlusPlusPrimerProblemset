#include<iostream>
#include<string>
using namespace std;
//函数1：既不交换指针所指对象，也不交换指针地址
void Swappointer1(int *p,int *q){
	int *temp = p;
	p = q;
	q = temp;
}

//该函数交换该指针所指的内容

void Swappointer2(int *p,int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}
//该函数交换该指针所指的内容，交换指针的值
void Swappointer3(int *&p,int *&q){
	int *temp = p;
	p = q;
	q = temp;
}

int main(){
	int a =10,b=5;
	int *p = &a,*q = &b;
	cout<<"交换前是："<<endl;
	cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
	cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;
	Swappointer1(p,q);
	cout<<"交换后是："<<endl;
	cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
	cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;
	cout<<"------------------------------------"<<endl;
	a =10,b=5;
	p = &a,q = &b;
	cout<<"交换前是："<<endl;
	cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
	cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;
	Swappointer2(p,q);
	cout<<"交换后是："<<endl;
	cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
	cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;
	cout<<"------------------------------------"<<endl;
	a =10,b=5;
	p = &a,q = &b;
	cout<<"交换前是："<<endl;
	cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
	cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;
	Swappointer3(p,q);
	cout<<"交换后是："<<endl;
	cout<<"p的值是："<<p<<",q的值是："<<q<<endl;
	cout<<"p所指的值是："<<*p<<",q所指的值是："<<*q<<endl;
	
	
	return 0;
}