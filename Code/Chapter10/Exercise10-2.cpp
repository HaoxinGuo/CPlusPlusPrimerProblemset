/*
ç»ƒä¹ 10-2
*/
#include<iostream>
#include<algorithm>
#include<vector>
#include<list>
#include<string>
#include<fstream>

using namespace std;

int main(){
	list<string> lstr = {"guo","hao","xin","guo"};
	string word = "guo";
	int cnt = count(lstr.begin(),lstr.end(),word);
	cout<<"The word "<< word <<" count "<<cnt<<" times."<<endl;
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter10\\data\\10-2string.txt");
	if(!in){
		cout<<"no data"<<endl;
		return -1;
	}
	cout<<"ÇëÊäÈëËÑË÷µÄµ¥´Ê"<<endl;
	string iword,jword;
	list<string> lstr1;
	cin>>iword;
	while(in>>jword)
		lstr1.push_back(jword);
	cout<<"The word "<< word <<" count "<< count(lstr1.begin(),lstr1.end(),iword)<<" times."<<endl;
	return 0;
}