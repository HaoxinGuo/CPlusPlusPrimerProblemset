#include<iostream>
#include<string>
using namespace std;
int main(){
	string s,s1;
	int i=0;
	cout<<"Please enter the first string s:"<<endl;
	getline(cin,s);
	/*
	while(s[i] != '\0'){
		s[i]='X';
		i++;
	}
	*/
	for(i=0,i<s.size(),++i)
		s[i]='X';
	cout<<"the result is "<< s <<endl;
	return 0;
}