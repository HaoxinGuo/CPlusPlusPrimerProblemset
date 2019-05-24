#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<deque>
using namespace std;

int main() {
	int ia[] = {1,1,2,3,5,8,13,21,55,89};
	vector<int> Vint(ia,end(ia));
	list<int> Lint(ia,end(ia));
	for(auto a:Vint)
		cout<<a<<" ";
	cout<<endl;
	for(auto a:Lint)
		cout<<a<<" ";
	cout<<endl;
	auto a = Vint.begin();
	while(a != Vint.end()){
		if ((*a) % 2==1)
			a = Vint.erase(a);
		else
			++a;
	}
	for(auto a = Lint.begin();a!=Lint.end();){
		if ((*a) % 2 == 0)
			a = Lint.erase(a);
		else
			++a;
	}
	for(auto a:Vint)
		cout<<a<<" ";
	cout<<endl;
	for(auto a:Lint)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}