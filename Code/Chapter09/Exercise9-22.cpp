#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<deque>
using namespace std;

int main() {
	vector<int> Vint = {1,2,1,1,56,1,1};
	auto Vbeg = Vint.begin();
	int ori_size = Vint.size();
	int new_ele = 0;
	int some_vale = 1;
	while(Vbeg != (Vint.begin()+ori_size/2 + new_ele)){
		if(*Vbeg == some_vale){
			Vbeg = Vint.insert(Vbeg,2*some_vale);
			new_ele++;
			Vbeg++;
			Vbeg++;
		}
		else
			Vbeg++;
	}
	for(auto a:Vint){
		cout<<a<<" ";
	}
	cout<<endl;
	return 0;
}