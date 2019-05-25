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
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-13.txt");
	if(!in){
		cout<<"No data"<<endl;
		return -1;
	}
	vector<string> words;
	istream_iterator<string> in_ter(in),eof;
	while(in_ter!=eof)
		words.push_back(*in_ter++);
	for(auto &a:words)
		cout<<a<< " ";
	cout<<endl;
	
	return 0;
}