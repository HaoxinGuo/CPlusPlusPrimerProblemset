//练习11-3

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
	// 统计每个单词在输入中出现的次数
	map<string, size_t> word_count; 	 // string到size_t的空map

	string word;
	cout<< "请输入记录的单词:"<<endl;
	while (cin >> word) {
		++word_count[word]; 	 //提取word的计数器并将其加1
	}
	
	for (const auto &w : word_count) // 对map中的每个元素
		// 打印结果
		cout << w.first << " occurs time: " << w.second << endl;

	return 0;
}
