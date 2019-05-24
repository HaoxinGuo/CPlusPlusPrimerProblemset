#include<iostream>
#include<vector>
using namespace std;
bool serach_vec(vector<int>::iterator beg,vector<int>::iterator end,int val){
	for(;beg!=end;++beg){
		if(*beg==val)
			return true;
	}
	return false;
}

int main(){
	vector<int> list={1,2,3,4,5,6,7,8,9};
	cout<<serach_vec(list.begin(),list.end(),3)<<endl;
	cout<<serach_vec(list.begin(),list.end(),10)<<endl;
	return 0;
}