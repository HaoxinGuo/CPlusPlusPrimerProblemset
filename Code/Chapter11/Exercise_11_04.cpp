//练习11-3

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

string &trans(string &s){
	for(int i =0;i<s.size();++i){
		if(s[i]>='A' && s[i]<='Z')
			s[i] -= ('A'-'a');
		else if(s[i]==','||s[i]=='.'){
			s.erase(p,1);
		}
	}
	return s;
}


int main()
{
	// 统计每个单词在输入中出现的次数
	map<string, size_t> word_count; 	 // string到size_t的空map

	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter11\\data\\11-04.txt");
	string word;
	cout<< "请输入记录的单词:"<<endl;
	while (cin >> word) {
		++word_count[trans(word)]; 	 //提取word的计数器并将其加1
	}
	
	for (const auto &w : word_count) // 对map中的每个元素
		// 打印结果
		cout << w.first << " occurs time: " << w.second << endl;

	return 0;
}
