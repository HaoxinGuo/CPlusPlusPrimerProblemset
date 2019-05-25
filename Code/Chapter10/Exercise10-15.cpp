/*
Exercise10-15
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>

using namespace std;

int main(){
	int i = 10;
	auto sum = [i](int j){return i+j;};
	cout<< sum(1) <<endl;
	return 0;
}