//��ϰ11-3

#include <iostream>
#include <string>
#include <set>
#include <map>
#include<vector>
#include<utility>
using namespace std;

void add_family(map<string, vector<pair<string,string>>>  &families,const string &family){
	if(families.find(family)==families.end())
		families[family] = vector<pair<string,string>>();
}

void add_child(map<string, vector<pair<string,string>>>  &families,const string &family,const string &child,const string &birthday){
	//families[family].push_back({child,birthday});
	families[family].push_back(make_pair(child,birthday));
}


int main()
{
	// ͳ��ÿ�������������г��ֵĴ���
	map<string, vector<pair<string,string>>> families; 	 // string �� vector<string>������

	add_family(families,"��");
	add_child(families,"��","��","1970-1-1");
	add_child(families,"��","ǿ","1970-1-1");
	add_child(families,"��","ǿ","1970-1-1");
	add_family(families,"��");
	add_child(families,"��","��","1970-1-1");
	for (const auto &w : families){// ��map�е�ÿ��Ԫ��
		// ��ӡ���
		cout << w.first << "�ҵĺ���:";
		for(auto &t: w.second)
			cout<< w.first << t.first <<"�ĳ�������Ϊ" << t.second << ",";
		cout<<endl;
	}

	return 0;
}
