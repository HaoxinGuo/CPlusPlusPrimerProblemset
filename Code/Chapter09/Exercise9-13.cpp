#include<iostream>
#include<vector>
#include<list>
using namespace std;

int main(){
	vector<int> ilist={1,2,3,4,5,6,7,8,9};
	list<int> list1 = {1,2,3,4,5,6,7,8,9,10};
	vector<double> dvec(ilist.begin(),ilist.end());
	vector<double> dvec1(list1.begin(),list1.end());
	cout<<dvec.capacity()<<" "<<dvec.size()<<" "<<dvec[0]<<" "<<dvec[dvec.size()-1]<<endl;
	cout<<dvec1.capacity()<<" "<<dvec1.size()<<" "<<dvec1[0]<<" "<<dvec1[dvec1.size()-1]<<endl;
	
	return 0;
}