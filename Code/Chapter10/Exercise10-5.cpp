/*
Exercise10-5
C����ַ���������char*���ͣ���==�Ƚ���char*����ֻ�Ǽ����ָ��ֵ�Ƿ����
����ַ�Ƿ���ȣ�����Ƚ������ַ��Ƿ���ȡ�
*/
#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int main(){
	const char *p[] = {"hello","word","!"};
	const char *q[] = {strdup(p[0]),strdup(p[1]),strdup(p[2])};
	const char *r[] = {p[0],p[1],p[2]};
	
	cout<<equal(begin(p),end(p),q)<<endl;
	cout<<equal(begin(p),end(p),r)<<endl;
	return 0;
}