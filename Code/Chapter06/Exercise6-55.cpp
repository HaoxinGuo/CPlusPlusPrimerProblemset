#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

int func1(int a,int b){
	return a+b;
}

int func2(int a,int b){
	return a-b;
}

int func3(int a,int b){
	return a*b;
}

int func4(int a,int b){
	return a/b;
}


void Compute(int i,int j,int(*p)(int,int)){
	cout<<p(i,j)<<endl;
}

int main(){
	int i=5,j=10;
	decltype(func1) *p1 = func1,*p2 = func2,*p3 = func3,*p4 = func4;
	vector<decltype(func1)*> vF ={p1,p2,p3,p4};
	for(auto p:vF){
		Compute(i,j,p);
	}
	return 0;
}