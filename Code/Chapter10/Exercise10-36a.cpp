/*
Exercise10-36list�ڴ治���������������֧����������
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
	
	auto last_z = find(Vint.rbegin(),Vint.rend(),0);
	last_z++;
	int p =1;
	for(auto it = Vint.begin();it!=last_z.
	base();it++,p++){
		
	}
	if(p>=Vint.size())
		cout<<"No Zero"<<endl;
	else
		cout<<"���һ��0�ڵ�"<<p<<"��λ�á�"<<endl;
	
	
	return 0;
}