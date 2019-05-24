#include<iostream>
#include<string>
#include<forward_list>
#include<list>
#include<vector>
//forward——list /list列表内存不连续

using namespace std;

int main() {
	vector<char> vc = {'h','e','l','l','o'};
	string s(vc.data(),vc.size());
	cout<<s<<endl;
	string s1(vc.begin(),vc.end());
	cout<<s1<<endl;
	return 0;
}