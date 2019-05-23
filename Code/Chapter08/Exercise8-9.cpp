#include<iostream>
#include<stdexcept>
#include<string>
#include<sstream>
using namespace std;
istream& read(istream& is){
	string i;
	while(is>>i , !is.eof()){
		if(is.bad())
			throw runtime_error("IOÁ÷´íÎó");
		if(is.fail()){
			cerr<<"Data is wrong"<<endl;
			is.clear();
			is.ignore(100,'\n');
			continue;
		}
		cout<<i<<endl;
	}
	is.clear();
	return is;
}
int main(){
	ostringstream msg;
	msg<<"C++ Primer µÚÎå°æ"<<endl;
	istringstream in(msg.str());
	read(in);
	return 0;
}