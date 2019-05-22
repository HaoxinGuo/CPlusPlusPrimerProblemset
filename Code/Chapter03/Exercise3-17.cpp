#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main(){
	vector<string> Vstring;
	string s;
	char cont ='y';
	cout<<"Please Enter string s£º"<<endl;
	while(cin>>s){
		Vstring.push_back(s);
		cout<<"Do you want to continue?y/n"<<endl;
		cin>>cont;
		if(cont!='y' && cont!='Y')
			break;
	}
	for(auto &c:Vstring){
		for(auto &m:c){
			m=toupper(m);
		}
		cout<<c<<endl;
	}
	return 0;
}