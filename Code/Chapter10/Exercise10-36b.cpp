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
	
	list<int> Vint;
	int i;
	while(in>>i){
		Vint.push_back(i);
	}
	
	auto pre = find(Vint.begin(),Vint.end(),0);
	
	if(pre==Vint.end())
		cout<<"No Zero"<<endl;
	
	else{
		auto curr = pre;
		while(curr!=Vint.end()){
		//记住上一个0的位置
			pre = curr;
			curr++;
			//寻找下一个0的位置
			curr = find(curr,Vint.end(),0);
		}
	int p = 1;
	//从链表头开始计数pre的位置
	for(auto it = Vint.begin();it!=pre;it++,p++){}
	cout<<"最后一个0在第"<<p<<"个位置。"<<endl;
	}
	
	return 0;
}