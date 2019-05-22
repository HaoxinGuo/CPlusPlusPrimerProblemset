#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	int value;
	char cont = 'y';
	vector<int> Vint;
	cout<<"Please enter the value："<<endl;
	while(cin>>value){
		Vint.push_back(value);
	}
	//处理Vint
	/*
	for(decltype(Vint.size()) i=0;i < Vint.size()-1;i+=2){
		cout<<Vint[i]+Vint[i+1]<<" ";
		if((i+2)%10==0)
			cout<<endl;
	}
	if(Vint.size()%2==1)
		cout<<Vint[Vint.size()-1]<<endl;
	*/
// 1 i-1首尾相加
	for(decltype(Vint.size()) i=0;i<Vint.size()/2;i++){
		cout<<Vint[i]+Vint[Vint.size()-1-i]<<" ";
		if(i%5==0)
			cout<<endl;
	}
	if(Vint.size()%2!=0)
		cout<<Vint[Vint.size()-1]<<endl;

	return 0;
}