#include<iostream>
#include<string>
using namespace std;
//����1���Ȳ�����ָ����ָ����Ҳ������ָ���ַ

int main(int argc,char **argv){
	string str;
	for( int i=0;i!=argc;++i){
		str +=argv[i];
	}
	cout<<argc<<endl;
	cout<<str<<endl;
	return 0;
}