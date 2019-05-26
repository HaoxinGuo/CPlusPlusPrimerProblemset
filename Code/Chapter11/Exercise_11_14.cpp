//练习11-3

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
	// 统计每个单词在输入中出现的次数
	map<string, vector<pair<string,string>>> families; 	 // string 名 vector<string>保存姓

	add_family(families,"张");
	add_child(families,"张","刚","1970-1-1");
	add_child(families,"张","强","1970-1-1");
	add_child(families,"郭","强","1970-1-1");
	add_family(families,"郭");
	add_child(families,"郭","鑫","1970-1-1");
	for (const auto &w : families){// 对map中的每个元素
		// 打印结果
		cout << w.first << "家的孩子:";
		for(auto &t: w.second)
			cout<< w.first << t.first <<"的出生日期为" << t.second << ",";
		cout<<endl;
	}

	return 0;
}
