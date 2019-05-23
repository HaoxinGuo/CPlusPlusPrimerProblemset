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


int main(){
	string line,word;
	vector<PersonInfo> people;
	istringstream record;
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
	return 0;
}