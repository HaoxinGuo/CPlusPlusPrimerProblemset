/*
Exercise10-20
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>
#include<functional>

using namespace std;
using namespace std::placeholders;

bool check_size(const string &s,string::size_type sz){
	return s.size() <= sz;
}

void large_than_string(const string &s,vector<int> &Vint){
	//���ҵ�һ�����ڵ���s���ȵ���ֵ
	auto p = find_if(Vint.begin(),Vint.end(),bind(check_size,s,_1));
	if(p==Vint.end())
		cout<<"No data large than s.size()"<<endl;
	else
		cout<< "��"<<p-Vint.begin()+1<< "���� "<<*p<< "���ڵ���"<<s<< "�ĳ���"<<endl;
}



int main() {
	vector<int> Vint= {1,2,3,5,6,8,10};
	large_than_string(string("hello"),Vint);
	large_than_string("helloooooo",Vint);
	return 0;
}