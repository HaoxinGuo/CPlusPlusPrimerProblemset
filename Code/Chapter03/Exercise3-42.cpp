#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
//c ·ç¸ñ×Ö·û´® strlen strcopy strcat
int main(){
	const int sz = 10;
	vector<int> Vint;
	srand((unsigned)time(NULL));
	cout<<"the content of Vint is:"<<endl;
	for(int i=0;i<sz;i++){
		Vint.push_back(rand()%100);
		cout<<Vint[i]<<" ";
	}
	cout<<endl;
	auto it=Vint.begin();
	int Val[Vint.size()];
	for(auto &val:Val){
		val = *it;
		it++;
		cout<<val<<" ";
	}
	cout<<endl;
	return 0;
}