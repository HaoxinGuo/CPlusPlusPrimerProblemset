/*
Exercise10-15
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>

using namespace std;

void output_words(vector<string> const &words){
	for(auto a:words)
		cout<<a<<" ";
	cout<<endl;
}

void elimDups(vector<string> &words){
	sort(words.begin(),words.end());
	auto end_unique = unique(words.begin(),words.end());
	words.erase(end_unique,words.end());
}


void biggers(vector<string> &words,vector<string>::size_type sz){
	elimDups(words);	//����������ͬ���ĵ���ɾ��
	//����������ͬ�����ȵĵ��ʰ��ֵ�������
	stable_sort(words.begin(),words.end(),[](const string &s1,const string &s2){return s1.size()<s2.size();});
	//��ȡһ����������ָ������s.size()����sz��Ԫ��
	auto wc = find_if(words.begin(),words.end(),[sz](const string &s1){return s1.size()>sz;});
	auto count = words.end()-wc;//�������sz����Ŀ��
	for_each(wc,words.end(),
							[](const string &s){cout<<s<<" ";});
	cout<<endl;
}

int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-13.txt");
	if(!in){
		cout<<"No data"<<endl;
		return -1;
	}
	string word;
	vector<string> words;
	while(in>>word)
		words.push_back(word);
	
	output_words(words);
	
	biggers(words,5);
	

	return 0;
}