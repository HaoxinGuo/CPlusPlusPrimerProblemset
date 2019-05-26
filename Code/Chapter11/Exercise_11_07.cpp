//��ϰ11-3

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
	// ͳ��ÿ�������������г��ֵĴ���
	map<string, vector<string> > families; 	 // string �� vector<string>������

	add_family(families,"��");
	add_child(families,"��","��");
	add_child(families,"��","ǿ");
	add_child(families,"��","ǿ");
	add_family(families,"��");
	add_child(families,"��","��");
	for (const auto &w : families){// ��map�е�ÿ��Ԫ��
		// ��ӡ���
		cout << w.first << " �ҵĺ���:";
		for(auto &t:w.second)
			cout << w.first << t<< " ";
		cout<<endl;
	}

	return 0;
}
