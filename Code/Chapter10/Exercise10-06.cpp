/*
Exercise10-6
*/
#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main(){
	vector<int> Vint = {10,10,10,10};
	fill_n(Vint.begin(),Vint.size(),0);
	for(auto a:Vint)
		cout << a << " ";
	cout<<endl;
	return 0;
}