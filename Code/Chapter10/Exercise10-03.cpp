/*
Á·Ï°10-3
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include<fstream>
#include<numeric>
using namespace std;

int main(){
	vector<int> Vint {1,23,4};
	int sum = accumulate(Vint.begin(),Vint.end(),0);
	cout<<"sum = "<< sum <<endl;
	return 0;
}