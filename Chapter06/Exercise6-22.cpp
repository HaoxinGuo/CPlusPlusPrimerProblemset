#include<iostream>
#include<string>
using namespace std;
//����1���Ȳ�����ָ����ָ����Ҳ������ָ���ַ
void Swappointer1(int *p,int *q){
	int *temp = p;
	p = q;
	q = temp;
}

//�ú���������ָ����ָ������

void Swappointer2(int *p,int *q){
	int temp = *p;
	*p = *q;
	*q = temp;
}
//�ú���������ָ����ָ�����ݣ�����ָ���ֵ
void Swappointer3(int *&p,int *&q){
	int *temp = p;
	p = q;
	q = temp;
}

int main(){
	int a =10,b=5;
	int *p = &a,*q = &b;
	cout<<"����ǰ�ǣ�"<<endl;
	cout<<"p��ֵ�ǣ�"<<p<<",q��ֵ�ǣ�"<<q<<endl;
	cout<<"p��ָ��ֵ�ǣ�"<<*p<<",q��ָ��ֵ�ǣ�"<<*q<<endl;
	Swappointer1(p,q);
	cout<<"�������ǣ�"<<endl;
	cout<<"p��ֵ�ǣ�"<<p<<",q��ֵ�ǣ�"<<q<<endl;
	cout<<"p��ָ��ֵ�ǣ�"<<*p<<",q��ָ��ֵ�ǣ�"<<*q<<endl;
	cout<<"------------------------------------"<<endl;
	a =10,b=5;
	p = &a,q = &b;
	cout<<"����ǰ�ǣ�"<<endl;
	cout<<"p��ֵ�ǣ�"<<p<<",q��ֵ�ǣ�"<<q<<endl;
	cout<<"p��ָ��ֵ�ǣ�"<<*p<<",q��ָ��ֵ�ǣ�"<<*q<<endl;
	Swappointer2(p,q);
	cout<<"�������ǣ�"<<endl;
	cout<<"p��ֵ�ǣ�"<<p<<",q��ֵ�ǣ�"<<q<<endl;
	cout<<"p��ָ��ֵ�ǣ�"<<*p<<",q��ָ��ֵ�ǣ�"<<*q<<endl;
	cout<<"------------------------------------"<<endl;
	a =10,b=5;
	p = &a,q = &b;
	cout<<"����ǰ�ǣ�"<<endl;
	cout<<"p��ֵ�ǣ�"<<p<<",q��ֵ�ǣ�"<<q<<endl;
	cout<<"p��ָ��ֵ�ǣ�"<<*p<<",q��ָ��ֵ�ǣ�"<<*q<<endl;
	Swappointer3(p,q);
	cout<<"�������ǣ�"<<endl;
	cout<<"p��ֵ�ǣ�"<<p<<",q��ֵ�ǣ�"<<q<<endl;
	cout<<"p��ָ��ֵ�ǣ�"<<*p<<",q��ָ��ֵ�ǣ�"<<*q<<endl;
	
	
	return 0;
}