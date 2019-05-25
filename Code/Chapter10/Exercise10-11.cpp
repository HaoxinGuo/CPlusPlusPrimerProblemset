/*
Exercise10-11
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>

using namespace std;
bool isshorter(const string &s1,const string &s2){
	return s1.size()<s2.size();
}


void elimDups(vector<string> &words){
	stable_sort(words.begin(),words.end(),isshorter);
	//auto end_unique = unique(words.begin(),words.end());
	//words.erase(end_unique,words.end());
}

int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-9.txt");
	if(!in){
		cout<<"No data"<<endl;
		return -1;
	}
	string word;
	vector<string> words;
	while(in>>word)
		words.push_back(word);
	for(auto a:words)
		cout<<a<<" ";
	cout<<endl;
	cout<< "--------------"<<endl;
	elimDups(words);
	for(auto a:words)
		cout<<a<< " ";
	cout<<endl;
	
	return 0;
}