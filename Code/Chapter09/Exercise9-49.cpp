#include<iostream>
#include<string>
#include<vector>
#include<fstream>
//forward——list /list列表内存不连续

using namespace std;

void find_longest_word(ifstream &in){
	string s,longest;
	int maxlength = 0;
	while(in>>s){
		if(s.find_first_of("bdfghjklpqty") != string::npos)
			continue;
		cout << s<<endl;
		if(maxlength<s.size()){
			maxlength = s.size();
			longest = s;
		}
	}
	cout<<"The longest string is "<< longest <<endl;
}



int main() {
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter09\\data.txt");
	if(!in){
		cerr<<"无法打开输入文件"<<endl;
		return -1;
	}
	find_longest_word(in);
	return 0;
}