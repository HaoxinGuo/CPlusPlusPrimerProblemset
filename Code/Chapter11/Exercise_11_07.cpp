//练习11-3

#include <iostream>
#include <string>
#include <set>
#include <map>
#include<vector>

using namespace std;

void add_family(map<string,vector<string>> &families,const string &family){
	if(families.find(family)==families.end())
		families[family] = vector<string>();
}

void add_child(map<string,vector<string>> &families,const string &family,const string &child){
	families[family].push_back(child);
}


int main()
{
	// 统计每个单词在输入中出现的次数
	map<string, vector<string> > families; 	 // string 名 vector<string>保存姓

	add_family(families,"张");
	add_child(families,"张","刚");
	add_child(families,"张","强");
	add_child(families,"郭","强");
	add_family(families,"郭");
	add_child(families,"郭","鑫");
	for (const auto &w : families){// 对map中的每个元素
		// 打印结果
		cout << w.first << " 家的孩子:";
		for(auto &t:w.second)
			cout << w.first << t<< " ";
		cout<<endl;
	}

	return 0;
}
