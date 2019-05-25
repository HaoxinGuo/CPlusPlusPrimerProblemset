/*
Exercise10-5
C风格字符串本质是char*类型，用==比较两char*对象，只是检查两指针值是否相等
即地址是否相等，不会比较其中字符是否相等。
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