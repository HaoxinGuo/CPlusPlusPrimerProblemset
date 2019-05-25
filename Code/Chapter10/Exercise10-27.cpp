/*
Exercise10-27
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>
#include<functional>

using namespace std;

int main(){
	vector<int> Vint = {1,1,23,45,6,23,7};
	list<int> lst,lst2,lst3;
	sort(Vint.begin(),Vint.end());
	unique_copy(Vint.begin(),Vint.end(),inserter(lst,lst.begin()));
	unique_copy(Vint.begin(),Vint.end(),front_inserter(lst2));
	unique_copy(Vint.begin(),Vint.end(),back_inserter(lst3));
	for(auto &a:lst)
		cout<<a<< " ";
	cout<<endl;
	for(auto &a:lst2)
		cout<<a<< " ";
	cout<<endl;
	for(auto &a:lst3)
		cout<<a<< " ";
	cout<<endl;
	return 0;
}