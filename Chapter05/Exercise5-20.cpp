#include<iostream>
#include<string>
using namespace std;
int main(){
	string currstring,prestrig;
	bool b = true;
	while(cin>>currstring){
		if(currstring ==prestrig){
			cout<<"�������γ��ֵ��ַ����ǣ�"<<currstring<<endl;
			b = false;
			break;
		}
		else
			prestrig = currstring;
	}
	if(b)
		cout<<"û�������������ֵ��ַ���"<<endl;
	return 0;
}