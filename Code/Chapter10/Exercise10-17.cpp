/*
Exercise10-12
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>
#include"Sales_data.h"

using namespace std;

/*
bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs){
	return lhs.isbn() < rhs.isbn();
}
*/

int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-12.txt");
	if(!in){
		cout<<"No data"<<endl;
		return -1;
	}
	Sales_data word;
	vector<Sales_data> words;
	while(read1(in,word))
		words.push_back(word);
	for(auto &a: words){
		print1(cout,a);
		cout<<endl;
	}
	cout<<"---------------------------"<<endl;
	sort(words.begin(),words.end(),[](const Sales_data &lhs,const Sales_data &rhs){return lhs.isbn() < rhs.isbn();});
	
	for(auto &a : words){
		print1(cout,a);
		cout<<endl;
	}
	
	return 0;
}