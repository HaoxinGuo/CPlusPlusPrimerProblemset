#include<iostream>
#include<string>
using namespace std;
int main(){
	string s,result;
	int i=0;
	cout<<"Please enter the first string s:"<<endl;
	getline(cin,s);
	
	for(auto c:s){
		if(!ispunct(c))
			cout<<c;
	}
	cout<<endl;
	/*
	for(i=0;i<s.size();++i){
		if(!ispunct(s[i]))
			result += s[i];
	}
	cout<<"the result is "<< result <<endl;
	*/
	return 0;
}