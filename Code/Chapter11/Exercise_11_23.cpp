//��ϰ11-3

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
	// ͳ��ÿ�������������г��ֵĴ���
	multimap<string, string> families; 	 // string �� vector<string>������

	add_family(families,"��","��");
	add_family(families,"��","ǿ");
	add_family(families,"��","ǿ");
	add_family(families,"��","��");
	for (const auto &w : families){// ��map�е�ÿ��Ԫ��
		// ��ӡ���
		cout << w.first << w.second<<endl;
	}

	return 0;
}
