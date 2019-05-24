#include<iostream>
#include<string>
#include<forward_list>
#include<list>
//forward——list /list列表内存不连续

using namespace std;

int main() {
	list<int> Lint = {1,2,3,4,5};
	auto curr = Lint.begin();
	while(curr!=Lint.end()){
		if(*curr & 1){
			curr = Lint.insert(curr,*curr);
			curr++;
			curr++;
		}
		else{
			curr = Lint.erase(curr);
		}
	}
	for(auto a:Lint)
		cout<<a<<" ";
	cout<<endl;
	cout<<"---------------------"<<endl;
	forward_list<int> Lint1 = {1,2,3,4,5};
	auto curr1 = Lint1.begin();
	auto pre = Lint1.before_begin();
	while(curr1!=Lint1.end()){
		if(*curr1 & 1){
			curr1 = Lint1.insert_after(curr1,*curr1);
			pre = curr1;
			curr1++;
		}
		else
			curr1 = Lint1.erase_after(pre);
	}
	for(auto a:Lint1)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}