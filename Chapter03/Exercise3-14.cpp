#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	vector<int> Vint;
	int i;
	char cont ='y';
	while(cin>>i){
		Vint.push_back(i);
		cout<<"Do you want to continue?y/n"<<endl;
		cin>>cont;
		if(cont!='y' && cont!='Y')
			break;
	}
	for(auto c:Vint){
		cout<<c<<endl;
	}
	return 0;
}