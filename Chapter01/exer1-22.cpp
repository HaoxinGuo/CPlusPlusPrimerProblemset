// C++primer课后练习题练习 1.21
#include<iostream>
#include"Sales_item.h"
using namespace std;
int main(){
	Sales_item total,book;
	cout<< "please enter sale_item total book "<<endl;
	if(cin>>total){
		while(cin>>book){
			if(compareIsbn(total,book))
				total = total + book;
			else{
				cout<< "Isbn is different"<<endl;
				return -1;
			}
		}
		cout<<total<<endl;
	}
	else{
		cout<<"no data"<<endl;
		return -1;
	}
	return 0;
}