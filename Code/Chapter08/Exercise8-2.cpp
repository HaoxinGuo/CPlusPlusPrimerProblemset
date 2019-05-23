#include<iostream>
#include<string>
#include<fstream>
#include<vector>
using namespace std;

int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter08\\data.txt");
	if(!in){
		cerr<<"无法打开输入文件"<<endl;
		return -1;
	}
	
	string line;
	vector<string> words;
	while(getline(in,line))
		words.push_back(line);
	in.close();
	auto it = words.begin();
	while(it != words.end()){
		cout<<*it<<endl;
		++it;
	}

	return 0;
}