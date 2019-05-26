//Á·Ï°11-8

#include <iostream>
#include <string>
#include <set>
#include <map>
#include<vector>
#include<algorithm>
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
	vector<string> words;
	string word;
	while(cin>>word){
		trans(word);
		if((find(words.begin(),words.end(),word) == words.end())){
			words.push_back(word);
		}
		else
			cout<<word<<"ÒÑ¾­´æÔÚ"<<endl;
	}
	for(auto &a:words)
		cout<<a<<" ";
	cout<<endl;
	return 0;
}
