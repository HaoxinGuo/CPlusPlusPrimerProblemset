//��ϰ11-3

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
	// ͳ��ÿ�������������г��ֵĴ���
	map<string, size_t> word_count; 	 // string��size_t�Ŀ�map

	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter11\\data\\11-04.txt");
	string word;
	cout<< "�������¼�ĵ���:"<<endl;
	while (cin >> word) {
		++word_count[trans(word)]; 	 //��ȡword�ļ������������1
	}
	
	for (const auto &w : word_count) // ��map�е�ÿ��Ԫ��
		// ��ӡ���
		cout << w.first << " occurs time: " << w.second << endl;

	return 0;
}
