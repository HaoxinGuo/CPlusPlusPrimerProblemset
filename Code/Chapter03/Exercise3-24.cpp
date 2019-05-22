#include<iostream>
#include<string>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	vector<int> Vint;
	int i;
	while(cin>>i)
		Vint.push_back(i);
	if(Vint.cbegin()==Vint.cend()){
		cout<<"No data"<<endl;
		return -1;
	}
	/*
	for(auto it=Vint.cbegin();it!=Vint.end()-1;it++){
		cout<< (*it+*(++it))<< " ";
		if((it-Vint.cbegin() + 1)%10==0)
			cout<<endl;
	}
	if(Vint.size()%2==1)
		cout<<*(Vint.end()-1)<<endl;
	*/
	// Ê×Î²Ïà¼Ó
	for(auto it=Vint.begin();it!=(Vint.end()-Vint.begin())/2+Vint.begin();it++){
		cout<< (*it+*(Vint.begin()+(Vint.end()-it)-1))<<" ";
		if((it-Vint.begin()+1)%5==0)
			cout<<endl;
	}
	if(Vint.size()%2==1)
		cout<<*(Vint.begin()+(Vint.end()-Vint.begin())/2)<<endl;
	return 0;
}