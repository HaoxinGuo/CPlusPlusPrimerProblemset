#include<iostream>
#include<string>
using namespace std;

bool HasUpper(const string &s){
	for(auto c:s){
		if(isupper(c))
			return true;
	}
	return false;
}

void Changelowwer(string &s){
	for(auto &c:s){
		c = tolower(c);
	}
}

int main(){
	cout<<"������һ���ַ���"<<endl;
	string s;
	cin>>s;
	if(HasUpper(s)){
		Changelowwer(s);
		cout<<"ת������ַ�����:"<<s<<endl;
	}
	else
		cout<<"�ַ���������д�ַ���"<<endl;
	return 0;
}