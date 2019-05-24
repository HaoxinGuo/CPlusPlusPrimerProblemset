#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<deque>
using namespace std;

void d_copy(list<int> &a,deque<int> &odd,deque<int> &even){
	auto abeg = a.begin();
	auto aend = a.end();
	for(;abeg!=aend;++abeg){
		if(*abeg % 2 ==0)
			even.push_back(*abeg);
		else 
			odd.push_back(*abeg);
	}
}

int main() {
	list<int> Lint{1,2,3,4,5,6};
	deque<int> dint1,dint2;
	d_copy(Lint,dint1,dint2);
	for(auto a:dint1)
		cout<<a<<" ";
	cout<<endl;
	for(auto a:dint2)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}