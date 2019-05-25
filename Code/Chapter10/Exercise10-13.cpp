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
bool Large_Five(const string &lhs){
	return lhs.size()>=5;
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
	for(auto &a:words)
		cout<<a<< " ";
	cout<<endl;
	auto it = partition(words.begin(),words.end(),Large_Five);
	words.erase(it,words.end());
	for(auto &a:words)
		cout<<a << " ";
	cout<<endl;
	
	
	
	return 0;
}