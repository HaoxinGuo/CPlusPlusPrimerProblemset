#include<iostream>
#include<string>
using namespace std;
int main(){
	string prestring = "",currstring,maxstring;
	int maxCnt = 0,currCnt = 1;
	while(cin>>currstring){
		if(currstring == prestring){
			++currCnt;
			if(currCnt>maxCnt){
				maxCnt = currCnt;
				maxstring = currstring;
			}
		}
		else
			currCnt = 1;
		prestring = currstring;
	}
	if(maxCnt>1)
		cout<<"The "<< maxstring << " occurres "<<maxCnt<<" times."<<endl;
	else
		cout<<"ÿ���ַ���ֻ����һ��"<<endl;
	return 0;
}