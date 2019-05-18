#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	cout<<"Please enter the first string s:"<<endl;
	getline(cin,s);
	for(auto &c:s){
		c='X';
	}
	/*3.7
	for(char &c : s){
		c='X';
	}
	*/
	cout<<"the result is "<< s <<endl;
	return 0;
}