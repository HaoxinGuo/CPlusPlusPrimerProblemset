//��ϰ11-8

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

	while(getline(in,line)){//��ȡһ��
		line_No++;		//�к�����
		istringstream l_in(line);		//�����ַ���������ȡ����
		while(l_in>>word){
			trans(word);
			word_lineNo[word].push_back(line_No);
		}
	}

	for(auto &a:word_lineNo){
		cout<<a.first<<" ��������: ";
		for(const auto &b : a.second){
			cout<< b<<" ";
		}
		cout<<endl;
	}

	return 0;
}
