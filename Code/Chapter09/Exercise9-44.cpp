#include<iostream>
#include<string>
#include<forward_list>
#include<list>
#include<vector>
//forward——list /list列表内存不连续

using namespace std;

void replace_string(string &s,const string &oldval,const string &newval){
	unsigned int p =0;
	while((p = s.find(oldval,p)) != string::npos){
		s.replace(p,oldval.size(),newval);
		p += newval.size();
	}
}



int main() {
	string s = "tho thro tho";
	replace_string(s,"thro","thooo");
	cout<<s<<endl;
	replace_string(s,"tho","thooo");
	cout<<s<<endl;
	return 0;
}