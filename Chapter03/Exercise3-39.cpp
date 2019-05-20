#include<iostream>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<cstring>
using namespace std;
//c ·ç¸ñ×Ö·û´®
int main(){
	char str1[80],str2[80];
	cout<<"Please enter the str1 and str2 "<<endl;
	cin>>str1>>str2;
	auto result = strcmp(str1,str2);
	switch(result){
		case 1:
			cout<<"str1>str2"<<endl;
			break;
		case -1:
			cout<<"str1<str2"<<endl;
			break;
		case 0:
			cout<<"str1=str2"<<endl;
			break;
		default:
			cout<<"weidingyi"<<endl;
			break;
	}
	return 0;
}