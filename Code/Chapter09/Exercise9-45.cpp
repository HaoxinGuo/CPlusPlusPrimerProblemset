#include<iostream>
#include<string>
#include<vector>
//forward——list /list列表内存不连续

using namespace std;

void name_string(string &name,const string &pre,const string &suf){
	name.insert(name.begin(),1,' ');
	name.insert(name.begin(),pre.begin(),pre.end());
	name.append(" ");
	name.append(suf.begin(),suf.end());
}



int main() {
	string name = "Haoxin";
	name_string(name,"Mr.","II");
	cout<<name<<endl;
	return 0;
}