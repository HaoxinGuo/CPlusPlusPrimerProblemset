/*
Exercise10-14
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>

using namespace std;

int main(){
	auto sum = [](int i,int j){return i+j;};
	cout<< sum(1,1) <<endl;
	return 0;
}