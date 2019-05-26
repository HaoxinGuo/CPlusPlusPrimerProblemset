//Á·Ï°11-11

#include<string>
#include <iostream>
#include <set>
#include<utility>
#include<vector>
using namespace std;

int main()
{
	string str;
	int val;
	vector<pair<string,int>> data;
	while(cin>>str && cin>>val){
		data.push_back(pair<string,int>(str,val));
	}
	for(const auto &a:data){
		cout<<a.first<<" "<<a.second<<endl;
	}
	
	return 0;
}