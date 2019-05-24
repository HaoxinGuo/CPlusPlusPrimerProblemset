#include<iostream>
#include<vector>
#include<list>
#include<string>
using namespace std;

bool l_v_equal(vector<int> &a,list<int> &b){
	if(a.size()!=b.size())
		return false;
	auto abeg = a.begin();
	auto aend = a.end();
	auto bbeg = b.begin();
	for(;abeg!=aend;++abeg,++bbeg)
		if(*abeg != *bbeg)
			return false;
	return true;
}


int main() {
	vector<int> Vint{1,2,3,4,5};
	list<int> Lint{1,2,4,5};
	cout<<l_v_equal(Vint,Lint)<<endl;
	return 0;
}