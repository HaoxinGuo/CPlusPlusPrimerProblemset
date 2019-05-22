#include<iostream>
#include<string>
using namespace std;
//函数1：既不交换指针所指对象，也不交换指针地址

int main(int argc,char **argv){
	string str;
	for( int i=0;i!=argc;++i){
		str +=argv[i];
	}
	cout<<argc<<endl;
	cout<<str<<endl;
	return 0;
}