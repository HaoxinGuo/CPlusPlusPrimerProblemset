#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
	const int sz =10;
	int a[sz],b[sz];
	int val;
	srand(unsigned(time(NULL)));
	for(int i=0;i<sz;i++){
		a[i]=rand()%10;
	}
	cout<<"the value is already done"<<endl;
	cout<<"Please int your number"<<endl;
	for(int i=0;i<sz;i++){
		if(cin>>val)
			b[i]=val;
	}
	cout<<"The system number is:"<<endl;
	for(auto i:a)
		cout<<i<<" ";
	cout<<endl;
	cout<<"Your enter number is "<<endl;
	for(auto j:b)
		cout<<j<<" ";
	cout<<endl;
	auto *p1 =begin(a);
	auto *p2 = begin(b);
	while( p1!= end(a) && p2!=end(b)){
		if(*p1!=*p2){
			cout<<"the number is different"<<endl;
			return -1;
		}
		p1++;
		p2++;
	}
	cout<<"Right"<<endl;
	return 0;
}