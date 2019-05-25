/*
Exercise10-35
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<iterator>
#include<string>
#include"Sales_data.h"

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
	for(auto it = Vint.cend();it!=Vint.cbegin();)
		cout<<*(--it)<<" ";
	cout<<endl;
	return 0;
}