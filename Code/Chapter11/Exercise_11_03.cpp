//��ϰ11-3

#include <iostream>
#include <string>
#include <set>
#include <map>

using namespace std;

int main()
{
	// ͳ��ÿ�������������г��ֵĴ���
	map<string, size_t> word_count; 	 // string��size_t�Ŀ�map

	string word;
	cout<< "�������¼�ĵ���:"<<endl;
	while (cin >> word) {
		++word_count[word]; 	 //��ȡword�ļ������������1
	}
	
	for (const auto &w : word_count) // ��map�е�ÿ��Ԫ��
		// ��ӡ���
		cout << w.first << " occurs time: " << w.second << endl;

	return 0;
}
