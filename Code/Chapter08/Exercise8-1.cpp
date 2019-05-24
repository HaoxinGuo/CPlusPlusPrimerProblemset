#include<iostream>
#include<stdexcept>
using namespace std;
istream& read(istream& is){
	int i;
	while(is>>i , !is.eof()){
		if(is.bad())
			throw runtime_error("IO������");
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
	cout<<"��������"<<endl;
	read(cin);
	return 0;
}