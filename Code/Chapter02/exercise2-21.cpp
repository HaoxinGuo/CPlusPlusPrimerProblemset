// C++primer�κ���ϰ����ϰ 2.21
// p1 *p1 ������
#include<iostream>
using namespace std;
int main(){
	int i=0;
	int *p1 = nullptr;
	int *p = &i;
	if(p1)
		cout<<"p1 pass"<<endl;
	if(p)
		cout<<"p pass"<<endl;
	if(*p)
		cout<<"*p pass."<<endl;
	return 0;
}