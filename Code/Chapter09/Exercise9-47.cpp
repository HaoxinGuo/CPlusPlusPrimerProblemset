#include<iostream>
#include<string>
#include<vector>
//forward——list /list列表内存不连续

using namespace std;

void find_num_str1(const string &s,const string &chars){
	cout<<"在"<<s<<"中查找"<<chars<<"的位置"<<endl;
	unsigned int p =0;
	while((p=s.find_first_of(chars,p)) != string::npos){
		cout<<"pos:"<<p<<", char:"<<s[p]<<endl;
		p++;
	}
}

void find_num_str2(const string &s,const string &chars){
	cout<<"在"<<s<<"中查找"<<chars<<"的位置"<<endl;
	unsigned int p =0;
	while((p=s.find_first_not_of(chars,p)) != string::npos){
		cout<<"pos:"<<p<<", char:"<<s[p]<<endl;
		p++;
	}
}



int main() {
	string s = {"gadgadhgertr131224453415dgdhefh56"};
	string num = {"0123456789"};
	find_num_str1(s,num);
	return 0;
}