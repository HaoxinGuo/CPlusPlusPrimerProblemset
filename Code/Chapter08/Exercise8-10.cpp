#include<iostream>
#include<stdexcept>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;

int main(){
	ifstream in("F:\\Cstudy\\CPlusPlusPrimerProblemset\\Code\\Chapter08\\data.txt");
	if(!in){
		cout<<"无法打开输入文件"<<endl;
		return -1;
	}
	string line;
	vector<string> words;
	while(getline(in,line)){
		words.push_back(line);
	}
	in.close();
	auto it = words.begin();
	while(it != words.end()){
		cout<< *it<<endl;
		cout<<"------------------"<<endl;
		istringstream line_str(*it);
		string word;
		while(line_str>>word){
			cout<<word<<" ";
		}
		cout << endl;
		++it;
	}
	return 0;
}