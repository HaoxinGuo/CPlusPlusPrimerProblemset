/*
Exercise10-36 
list�ڴ治���������������֧����������
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
		//��ס��һ��0��λ��
			pre = curr;
			curr++;
			//Ѱ����һ��0��λ��
			curr = find(curr,Vint.end(),0);
		}
	int p = 1;
	//������ͷ��ʼ����pre��λ��
	for(auto it = Vint.begin();it!=pre;it++,p++){}
	cout<<"���һ��0�ڵ�"<<p<<"��λ�á�"<<endl;
	}
	
	return 0;
}