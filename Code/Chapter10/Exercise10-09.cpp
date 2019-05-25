/*
Exercise10-7
```
vector<int> vec; list<int> lst; int i;
while (cin >> i)
	lst.push_back(i);
copy(lst.cbegin(), lst.cend(), vec.begin());
                               ^
							   错误，vec为空，应该改写为back_inserter(vec)
```
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<string>

using namespace std;

void elimDups(vector<string> &words){
	sort(words.begin(),words.end());
	auto end_unique = unique(words.begin(),words.end());
	words.erase(end_unique,words.end());
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