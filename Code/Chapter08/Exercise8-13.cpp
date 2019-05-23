#include<iostream>
#include<stdexcept>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>

using namespace std;
struct PersonInfo{
	string name;
	vector<string> phone;
};

string format(const string &s){return s;};

bool valid(const string &s){
	return true;
};

int main(int argc,char *argc){
	string line,word;
	vector<PersonInfo> people;
	istringstream record;
	
	if(argc!=2){
		cout<<"请给出文件名"<<endl;
		return -1;
	}
	
	ifstream in(argc[1]);
	if(!in){
		cerr<<"无法打开文件。"<<endl;
		return -1;
	}
	
	while(getline(cin,line)){
		PersonInfo info;
		record.clear();
		record.str(line);
		record>>info.name;
		while(record>>word){
			info.phone.push_back(word);
		}
		people.push_back(info);
	}
	
	ostringstream os;
	for(const auto &entry:people){
		ostringstream formatted,badnum;
		for(const auto &nums:entry.phone){
			if(valid(nums))
				badnum<<" "<< nums;
			else
				formatted<<" "<<format(nums);
			if(badnum.str().empty())
				os<<entry.name<<" "<<formatted.str()<<endl;
			else
				cerr<<"Input error:"<<entry.name<<"Ilvalid numbers "<<badnum.str()<<endl;
		}
		cout<<os.str()<<endl;
	}
	return 0;
}