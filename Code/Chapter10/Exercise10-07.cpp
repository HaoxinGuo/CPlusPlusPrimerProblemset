/*
Exercise10-7
```
vector<int> vec; list<int> lst; int i;
while (cin >> i)
	lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
                               ^
							   ����vecΪ�գ�Ӧ�ø�дΪback_inserter(vec)
```
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
using namespace std;

int main(){
	vector<int> vec;
	list<int> lst;
	int i;
	while(cin>>i)
		lst.push_back(i);
	copy(lst.begin(),lst.end(),back_inserter(vec));
	for(auto a:lst)
		cout<<a<<" ";
	cout<<endl;
	cout<<"--------------------"<<endl;
	for(auto a:vec)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}