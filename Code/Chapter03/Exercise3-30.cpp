#include<iostream>
#include<vector>
using namespace std;
int main(){
	const int sz =10;
	int a[sz],b[sz];
	for(int i=0;i<sz;++i)
		a[i]=i;
	for(int j=0;j<sz;++j)
		b[j]=a[j];
	for(auto i:a)
		cout<< i<< " ";
	cout<<endl;
	for(auto j:b)
		cout<<j<<" ";
	cout<<endl;
	return 0;
}