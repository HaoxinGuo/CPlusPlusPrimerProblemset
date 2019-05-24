#include<iostream>
#include<string>
#include<vector>
#include<fstream>
//forward——list /list列表内存不连续

using namespace std;

int main() {
	vector<string> vs = {"13","+45","-15"};
	float sum =0;
	for(auto a:vs)
		sum += stof(a);
	cout<<sum<<endl;
	return 0;
}