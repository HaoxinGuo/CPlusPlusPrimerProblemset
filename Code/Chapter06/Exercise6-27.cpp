#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;
//函数1：既不交换指针所指对象，也不交换指针地址

int Mysum(initializer_list<int> val){
	int sum =0;
	for(auto it=val.begin();it!=val.end();++it)
		sum += *it;
	return sum;
}

int main(){
	initializer_list<int> val = {1,2,23,4};
	int sum =Mysum(val);
	cout<<sum<<endl;
	return 0;
}