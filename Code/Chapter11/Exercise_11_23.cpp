//练习11-3

#include <iostream>
#include <string>
#include <set>
#include <map>
#include<vector>

using namespace std;

void add_family(multimap<string, string>&families,const string &family,const string &child){
	families.insert({family,child});
}



int main()
{
	// 统计每个单词在输入中出现的次数
	multimap<string, string> families; 	 // string 名 vector<string>保存姓

	add_family(families,"张","刚");
	add_family(families,"张","强");
	add_family(families,"郭","强");
	add_family(families,"郭","鑫");
	for (const auto &w : families){// 对map中的每个元素
		// 打印结果
		cout << w.first << w.second<<endl;
	}

	return 0;
}
