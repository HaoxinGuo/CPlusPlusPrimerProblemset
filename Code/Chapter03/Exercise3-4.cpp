#include<iostream>
#include<string>
using namespace std;
int main(){
	string s1,s2;
	cout<<"please enter two string s1 and s2:"<<endl;
	cin>>s1>>s2;
	/*
	//比较大小
	if(s1==s2){
		cout<<"s1 = s2"<<endl;
	}
	else if(s1>s2)
		cout<<s1<<" is large than "<<s2<<endl;
	else
		cout<<s1<<" is small than "<<s2<<endl;
	*/
	//比较长度
	auto l1 = s1.size();
	auto l2 = s2.size();
	if(l1==l2)
		cout<< s1 <<" is equal with "<<s2 <<" and the length is " <<l1<<endl;
	else if(l1>l2)
		cout<< s1 <<" is large than "<<s2 <<" and the length is " <<l1-l2<<endl;
	else
		cout<< s1 <<" is small than "<<s2 <<" and the length is " <<l2-l1<<endl;
	return 0;
}