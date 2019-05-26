//练习11-8

#include <iostream>
#include <string>
#include<fstream>
#include <map>
#include<vector>
#include<algorithm>
#include<sstream>
#include<list>

using namespace std;

string &trans(string &str){
	for(int i = 0;i<str.size();++i){
		if(str[i]==','||str[i]=='.')
			str.erase(i,1);
		str[i] = tolower(str[i]);
	}
	return str;
}

int main()
{
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter11\\data\\11-09.txt");
	if(!in){
		cout<<"Nodata"<<endl;
		cout<<endl;
	}

	map<string,list<int>> word_lineNo;
	string line;
	string word;
	int line_No = 0;

	while(getline(in,line)){//读取一行
		line_No++;		//行号增加
		istringstream l_in(line);		//构造字符串流，读取单词
		while(l_in>>word){
			trans(word);
			word_lineNo[word].push_back(line_No);
		}
	}

	for(auto &a:word_lineNo){
		cout<<a.first<<" 所在行有: ";
		for(const auto &b : a.second){
			cout<< b<<" ";
		}
		cout<<endl;
	}

	return 0;
}
