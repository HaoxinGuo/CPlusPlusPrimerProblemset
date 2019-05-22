// C++primer课后练习题练习 1.16
#include<iostream>
using namespace std;
int main(){
	int currVal = 0,val =0;
	if (cin>>currVal){
		int cnt = 1;
		while(cin >> val){
			if(val == currVal)
				++cnt;
			else{
				cout<< currVal << " occurs " << cnt << "times."<< endl;
				cnt = 1;
				currVal = val;
			}
		}
		cout<< currVal <<" occurs " << cnt << "times." << endl;
	}
}