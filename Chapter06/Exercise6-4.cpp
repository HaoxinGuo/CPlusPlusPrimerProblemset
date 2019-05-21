#include<iostream>
using namespace std;
int fact(int val){
	if(val<0)
		return -1;
	int ret = 1;
	for(int i=1;i<val+1;++i)
		ret *=i;
	return ret;
}
int main(){
	cout<<"请输入一个数："<<endl;
	int val;
	cin>>val;
	int J = fact(val);
	cout<<"val"<<"的阶乘是"<<J<<endl;
	return 0;
}