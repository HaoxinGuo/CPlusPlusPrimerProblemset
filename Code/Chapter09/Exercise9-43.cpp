#include<iostream>
#include<string>
#include<forward_list>
#include<list>
#include<vector>
//forward����list /list�б��ڴ治����

using namespace std;

void replace_string(string &s,const string &oldval,const string &newval){
	auto l = oldval.size();
	if(!l)
		return;
	auto iter = s.begin();
	while(iter <= s.end()-1){
		auto iter1 = iter;
		auto iter2 = oldval.begin();
		// s��iter��ʼ���Ӵ�����ÿ���ַ������
		while(iter2 != oldval.end() && *iter1==*iter2){
			iter1++;
			iter2++;
		}
		if(iter2==oldval.end()){
			iter = s.erase(iter,iter1);
			if(newval.size()){
				iter2 = newval.end();
				do{
					iter2--;
					iter = s.insert(iter,*iter2);
				} while(iter2>newval.begin());
			}
		iter = iter + newval.size();
		}
		else 
			iter++;
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