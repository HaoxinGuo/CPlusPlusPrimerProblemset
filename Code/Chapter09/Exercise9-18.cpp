#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<deque>
using namespace std;


int main() {
	deque<string> dstr;
	string word;
	while(cin>>word)
		dstr.push_back(word);
	for(auto it = dstr.begin();it!=dstr.end();++it)
		cout<<*it<<" ";
	cout<<endl;
	return 0;
}