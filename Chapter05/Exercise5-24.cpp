#include<iostream>
#include<string>
using namespace std;
int main(){
	int val1,val2;
	cout<<"��������������"<<endl;
	/*
	cin>>val1>>val2;
	if(val2==0){
		throw runtime_error("��ĸ����Ϊ0");
	}
	*/
	while(cin>>val1>>val2){
		try{
			if(val2==0)
				throw runtime_error("��ĸ����Ϊ0");
			cout<<"����������Ľ���ǣ�"<<val1/val2<<endl;
			break;
		}catch(runtime_error err){
			cout<<err.what()<<endl;
			cout<<"������y/n"<<endl;
			char ch;
			cin>>ch;
			if(ch != 'y'&&ch !='Y')
				break;
		}
	}
	return 0;
}