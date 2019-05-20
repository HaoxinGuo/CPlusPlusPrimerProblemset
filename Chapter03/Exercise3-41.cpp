#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
//c ·ç¸ñ×Ö·û´® strlen strcopy strcat
int main(){
	const int sz = 10;
	int val[sz];
	srand((unsigned) time(NULL));
	cout<<" the content of val is :"<<endl;
	for(auto &a:val){
		a = rand() % 100;
		cout<< a << " ";
	}
	cout<<endl;
	vector<int> Vint(begin(val),end(val));
	cout<<begin(val)<<endl;
	cout<<"the content of Vint is "<<endl;
	for(auto a:Vint){
		cout<<a<<" ";
	}
	cout<<endl;
	return 0;
}