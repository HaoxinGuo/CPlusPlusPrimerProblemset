/*
Exercise10-32
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
bool compareIsbn(const Sales_data &s1,const Sales_data &s2){
	return s1.isbn() < s2.isbn();
}


int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-12.txt");
	if(!in){
		cout<<"No data"<<endl;
		return -1;
	}
	
	vector<Sales_data> vs;
	istream_iterator<Sales_data> in_iter(in),eof;
	
	while(in_iter!=eof){
		vs.push_back(*in_iter++);
	}
	
	if(!vs.empty()){
		cout<<"No Data"<<endl;
		return -1;
	}
	
	sort(vs.begin(),vs.end(),compareIsbn);
	
	auto l = vs.begin();
	while(l!=vs.end()){
		auto item = *l;
		auto r = find_if(l+1,vs.end(),[item](const Sales_data &item1){return item1.isbn()!=item.isbn();});
		//cout<<accumulate(l+1,r,item)<<endl;
		l = r;
	}
	return 0;
}