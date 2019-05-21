#include<iostream>
#include<string>
using namespace std;

int find_char(const string &s,char c,int &occurs){
	auto ret = s.size();
	for(int i=0;i!=s.size();++i)
		if(s[i]==c){
			if(ret==s.size())
				ret = i;
			++occurs;
		}
	return ret;
}

int main(){
	string s="abcdddddd";
	int occurs = 0;
	auto t = find_char(s,'d',occurs);
	cout<<t<<" "<<occurs<<endl;
	return 0;
}