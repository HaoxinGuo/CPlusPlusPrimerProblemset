#include<iostream>
#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	int x=10,y=20;
	bool somevalue = true;
	somevalue ? ++x,++y:--x,--y;
	cout<<x<<endl;
	cout<<y<<endl;
	cout<<somevalue<<endl;
	x=10,y=20;
	
	somevalue = false;
	somevalue ? ++x,++y:--x,--y;
	cout<<x<<endl;
	cout<<y<<endl;
	cout<<somevalue<<endl;
	return 0;
}
