/*
练习10-1
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	vector<int> Vint{1,2,34,2,4,6,7,3,2,32,2,2,2};
	int num = 2;
	int cnt = count(Vint.begin(),Vint.end(),num);
	cout<<"The number "<< num<<" count "<<cnt<<" times."<<endl;
	return 0;
}