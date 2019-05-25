#include<iostream>
#include<string>
using namespace std;
int main(){
	char cont = 'y';
	string s,result;
	cout<<"Please enter the first string s:"<<endl;
	while(cin>>s){
		if(!result.size())
			result +=s;
		else
			result = result + ' ' + s;
		cout<<"Do you want to continue? y/n"<<endl;
		cin >>cont;
		if(cont=='y'||cont=='Y')
			cout<<"Please continue enter string s:"<<endl;
		else
			break;
	}
	cout<<"the result is "<<result<<endl;
	return 0;
}