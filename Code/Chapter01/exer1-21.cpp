// C++primer课后练习题练习 1.21
#include<iostream>
#include"Sales_item.h"
using namespace std;
int main(){
	Sales_item book1,book2;
	cout<< "please enter sale_item book1 book2 "<<endl;
	cin >> book1 >> book2;
	if(compareIsbn(book1,book2))
		cout << book1+book2<<endl;
	else
		cout <<"input book1.Isbn !=book2.isbn"<<endl;
	return 0;
}