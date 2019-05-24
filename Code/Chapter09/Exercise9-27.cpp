#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<deque>
#include<forward_list>
using namespace std;

int main() {
	int ia[] = {1,1,2,3,5,8,13,21,55,89};
	forward_list<int> Vint(ia,end(ia));
	auto pre = Vint.before_begin();
	auto cur = Vint.begin();
	while(cur != Vint.end()){
		if(*cur % 2 ==1)
			cur = Vint.erase_after(pre);
		else{
			pre = cur;
			++cur;
		}
	}
	for(auto a:Vint)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}