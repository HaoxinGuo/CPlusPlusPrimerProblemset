/*
Exercise10-3
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
	vector<double> Vd {1.2,23.5,4.9};
	double sum = accumulate(Vd.begin(),Vd.end(),0);
	cout<<"sum = "<< sum <<endl;
	sum = accumulate(Vd.begin(),Vd.end(),0.0);
	cout<<"sum = "<< sum <<endl;
	return 0;
}