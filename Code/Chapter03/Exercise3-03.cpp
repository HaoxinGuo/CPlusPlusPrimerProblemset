#include<iostream>
#include<string>
using namespace std;
int main(){
	string word,line;
	cout<<"please choose which way you want to output 1:word by word 2:line by line,"<<endl;
	char input;
	cin>>input;
	if(input=='1'){
		cout<<"please enter the string: Welcome to C++!"<<endl;
		cin>>word;
		cout<<"your input word output::"<<endl;
		cout<<word<<endl;
		return 0;
	}
	if(input=='2'){
		cout << "please enter the string: Welcome to C++!"<<endl;
		getline(cin,line);
		cout<<"your input word output::"<<endl;
		cout<<line<<endl;
		return 0;
	}
	cout<<"your input is wrong"<<endl;
	return -1;
}