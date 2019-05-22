#include<iostream>
#include<vector>
using namespace std;
int main(){
	vector<int> Vint(11,0);
	auto it = Vint.begin();
	int i;
	cout<<"please enter the grade"<<endl;
	while(cin>>i){
		if(i<101){
			++*(it+i/10);
		}
	}
	cout<<"the number you input is "<<Vint.size()<<endl;
	cout<<"the range is:"<<endl;
	for(auto it=Vint.begin();it!=Vint.end();it++){
		cout<<*it<<" ";
	}
	cout<<endl;
	return 0;
}