#include<iostream>
#include<vector>
using namespace std;
int main(){
	const int sz =10;
	int a[sz],b[sz];
	for(int i=0;i<sz;++i)
		a[i]=i;
	for(auto i:a)
		cout<< i<< " ";
	cout<<endl;
	int *p = begin(a);
	while(p!=end(a)){
		*p=0;
		p++;
	}
	for(auto i :a)
		cout<<i<<" ";
	cout<<endl;
	return 0;
}