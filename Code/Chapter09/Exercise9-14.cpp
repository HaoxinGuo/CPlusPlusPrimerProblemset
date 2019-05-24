#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

int main() {
	list<const char *> lchar = {"hell","welcome"};
	vector<string> svec;
	vector<int> Vint = { 1,2,3 };
	svec.assign(lchar.begin(), lchar.end());
	for (auto a : svec)
		cout << a << endl;
	for (auto it = svec.begin(); it != svec.end(); it++)
		cout << *it << endl;
	return 0;
}