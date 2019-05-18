// C++primer¿ÎºóÁ·Ï°ÌâÁ·Ï° 2.20
#include<iostream>
using namespace std;
int main(){
	int i=50;
	int *p = &i;
	cout<<*p<<endl;
	*p = *p * *p;
	cout<<*p<<endl;
	return 0;
}