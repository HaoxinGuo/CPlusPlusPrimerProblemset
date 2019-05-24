// C++primer课后练习题练习 1.16
#include<iostream>
#include"Sales_item.h"
using namespace std;
int main(){
	Sales_item book;
	cout<< "please enter sale_item"<<endl;
	while(cin >> book)
		cout<< book<<endl;
	return 0;
}