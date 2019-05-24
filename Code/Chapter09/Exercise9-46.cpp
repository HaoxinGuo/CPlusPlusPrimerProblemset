#include<iostream>
#include<string>
#include<vector>
//forward——list /list列表内存不连续

using namespace std;

void name_string(string &name,const string &pre,const string &suf){
	name.insert(0," ");
	name.insert(0,pre);
	name.insert(name.size()," ");
	name.insert(name.size(),suf);
	
}



int main() {
	string name = "Haoxin";
	name_string(name,"Mr.","II");
	cout<<name<<endl;
	return 0;
}