#include<iostream>
#include<string>
using namespace std;
int main(){
	string currstring,prestrig;
	bool b = true;
	while(cin>>currstring){
		if(currstring ==prestrig){
			cout<<"连续两次出现的字符串是："<<currstring<<endl;
			b = false;
			break;
		}
		else
			prestrig = currstring;
	}
	if(b)
		cout<<"没有两次连续出现的字符串"<<endl;
	return 0;
}