#include<iostream>
#include<string>
#include<initializer_list>
using namespace std;
//����1���Ȳ�����ָ����ָ����Ҳ������ָ���ַ

int Mysum(initializer_list<int> val){
	int sum =0;
	for(auto it=val.begin();it!=val.end();++it)
		sum += *it;
	return sum;
}

int main(){
	initializer_list<int> val = {1,2,23,4};
	int sum =Mysum(val);
	cout<<sum<<endl;
	return 0;
}