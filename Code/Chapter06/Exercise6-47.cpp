#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

void print(vector<int> Vint,unsigned int index){
	unsigned int sz = Vint.size();
	#ifndef NDEBUG
	cout<<"vector的大小是："<<sz<<endl;
	#endif
	if(!Vint.empty() && index < sz){
		cout<<Vint[index]<<" ";
		print(Vint,index+1);
	}
	cout<<endl;
}

int main(){
	srand((unsigned)time(NULL));
	const int sz = 10;
	vector<int> Vint;
	for(int i=0;i<sz;++i){
		Vint.push_back(rand()%100);
		cout<<Vint[i]<<" ";
	}
	cout<<endl;
	cout<<"----------------------------"<<endl;
	print(Vint,unsigned int a = 0);
	return 0;
}