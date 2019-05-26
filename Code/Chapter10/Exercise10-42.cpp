/*
Exercise10-42 
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<iterator>
#include<string>

using namespace std;

void elimDump(list<string> &s){
	s.sort();
	
	s.unique();
	
}



int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-2string.txt");
	if(!in){
		cout<<"No data"<<endl;
		return -1;
	}
	
	list<string> Vint;
	string i;
	while(in>>i){
		Vint.push_back(i);
	}
	
		for(auto &a:Vint)
		cout<<a<<" ";
	cout<<endl;
	
	elimDump(Vint);

	for(auto &a:Vint)
		cout<<a<<" ";
	cout<<endl;
	
	return 0;
}