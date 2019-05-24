#include<iostream>
#include<string>
#include<forward_list>
using namespace std;
void test_and_insert(forward_list<string> &flstr,const string &s1,const string &s2){
	bool inserted = false;
	auto pre = flstr.before_begin();
	auto cur = flstr.begin();
	while(cur!=flstr.end()){
		if(*cur == s1){
			cur = flstr.insert_after(cur,s2);
			inserted = true;
			break;
		}
		pre = cur;
		cur++;
	}
	if(!inserted)
		cur = flstr.insert_after(pre,s2);
}



int main() {
	forward_list<string> sflst={"hello","Hi"};
	test_and_insert(sflst,"hello","nihao");
	for(auto a:sflst)
		cout<<a<<" ";
	cout<<endl;
	test_and_insert(sflst,"bye","nihao");
	for(auto a:sflst)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}