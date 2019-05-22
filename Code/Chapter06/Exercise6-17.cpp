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
	cout<<"ÇëÊäÈëÒ»¸ö×Ö·û´®"<<endl;
	string s;
	cin>>s;
	if(HasUpper(s)){
		Changelowwer(s);
		cout<<"×ª»»ºóµÄ×Ö·û´®ÊÇ:"<<s<<endl;
	}
	else
		cout<<"×Ö·û´®²»º¬´óÐ´×Ö·û¡£"<<endl;
	return 0;
}