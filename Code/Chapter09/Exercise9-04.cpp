#include<iostream>
#include<vector>
using namespace std;
vector<int>::iterator serach_vec(vector<int>::iterator beg,vector<int>::iterator end,int val){
	for(;beg!=end;++beg){
		if(*beg==val)
			return beg;
	}
	return end;
}

int main(){
	vector<int> list={1,2,3,4,5,6,7,8,9};
	cout<<serach_vec(list.begin(),list.end(),3) - list.begin()<<endl;
	cout<<serach_vec(list.begin(),list.end(),10) - list.begin()<<endl;
	return 0;
}