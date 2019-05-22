#include<iostream>
#include<string>
using namespace std;
int main(){
	int val1,val2;
	cout<<"请输入两个整数"<<endl;
	/*
	cin>>val1>>val2;
	if(val2==0){
		throw runtime_error("分母不能为0");
	}
	*/
	while(cin>>val1>>val2){
		try{
			if(val2==0)
				throw runtime_error("分母不能为0");
			cout<<"两个数相除的结果是："<<val1/val2<<endl;
			break;
		}catch(runtime_error err){
			cout<<err.what()<<endl;
			cout<<"继续吗？y/n"<<endl;
			char ch;
			cin>>ch;
			if(ch != 'y'&&ch !='Y')
				break;
		}
	}
	return 0;
}