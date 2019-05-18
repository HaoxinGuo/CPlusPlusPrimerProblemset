#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	vector<int> Vint;
	srand((unsigned)time(NULL));
	for(int i=0;i<10;i++)
		Vint.push_back(rand()%1000);
	cout<<"the value is:"<<endl;
	for(auto it = Vint.cbegin();it != Vint.cend();it++)
		cout<<*it<<" ";
	cout<<endl;
	//翻倍后的结果
	cout<<"the value is two times:"<<endl;
	for(auto it = Vint.begin();it != Vint.end();it++){
		*it *=2;
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}