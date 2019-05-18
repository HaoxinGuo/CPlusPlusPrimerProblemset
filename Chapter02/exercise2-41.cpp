// C++primer课后练习题练习 2.21
// p1 *p1 的区别
#include"Sales_data.h"
//using namespace std;
int main() {
	Sales_data book;
	cout<<"Please enter  bookNo units_sold saleprice sellingprice"<<endl;
	while(cin >> book){
		cout<<"Isbn units_sold saleprice sellingprice discount " << book <<endl;
	}
	Sales_data trans1,trans2;
	cout<<"plese enter the bookNo is equal"<<endl;
	cin>>trans1>>trans2;
	if(compareIsbn(trans1,trans2))
		cout<<"Isbn units_sold saleprice sellingprice discount " 
		<< trans1+trans2 <<endl;
	else
		cout<<"the bookNo is different"<<endl;
	Sales_data total,trans;
	if(cin>>total){
		while(cin>>trans){
			if(compareIsbn(total,trans)){
				total += trans;
			}
			else{
				cout<<"the Isbn is different"<<endl;
				break;
			}
		}
		cout<<"Isbn units_sold saleprice sellingprice discount " <<total<<endl;
	}
	else{
		cout<<"No data"<<endl;
		return -1;
	}
	
	int num =1;//记录当前书籍的数量
	cout<<"please bookNo "<<endl;
	if(cin>>trans1){
		while(cin>>trans2){
			if(compareIsbn(trans1,trans2)){
				num++;
			}
			else{
				cout<<trans1.isbn()<< " has "<<num<<" numbers."<<endl;
				trans1=trans2;
				num=1;
			}
		}
		cout<<trans1.isbn()<< " has "<<num<<" numbers."<<endl;
	}
	else{
		cout<<"No data"<<endl;
		return -1;
	}
	return 0;
}