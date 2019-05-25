/*
Exercise10-20
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>

using namespace std;

void mutable_lambda(void){
	int i=5;
	auto f = [i]()mutable->bool{if(i>0){i--;return false;}else return true;};
	
	for(int j=0;j<6;++j)
		cout<<f()<<" ";
	cout<<endl;
}

int main(){
	int i =10;
	mutable_lambda();
	return 0;
}