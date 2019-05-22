#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;

void print(vector<int> Vint,int index){
	unsigned sz = Vint.size();
	if(!Vint.empty() && index<sz){
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
	print(Vint,0);
	return 0;
}