/*
Exercise10-15
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<fstream>
#include<iterator>
#include<string>

using namespace std;

int main(){
	vector<int> words;
	istream_iterator<int> in_ter(cin),eof;
	while(in_ter!=eof)
		words.push_back(*in_ter++);
	
	sort(words.begin(),words.end());
	
	ostream_iterator<int> out_iter(cout, " ");
	
	copy(words.begin(),words.end(),out_iter);
	
	return 0;
}