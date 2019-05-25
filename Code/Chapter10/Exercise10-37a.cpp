/*
Exercise10-36 
list内存不连续，其迭代器不支持算术运算
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<iterator>
#include<string>

using namespace std;


int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-33.txt");
	if(!in){
		cout<<"No data"<<endl;
		return -1;
	}
	
	vector<int> Vint;
	int i;
	while(in>>i){
		Vint.push_back(i);
	}
	
	
	list<int> li;
	
	vector<int>::reverse_iterator re(Vint.begin()+2);
	vector<int>::reverse_iterator rb(Vint.begin()+7);
	
	copy(rb,re,back_inserter(li));
	for(auto &a:li)
		cout<<a<<" ";
	cout<<endl;
	
	return 0;
}