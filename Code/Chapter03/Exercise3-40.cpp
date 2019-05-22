#include<iostream>
#include<cstring>
using namespace std;
//c ·ç¸ñ×Ö·û´® strlen strcopy strcat
int main(){
	char str1[] = "Welcome to ";
	char str2[] = "C++ family ";
	char result[strlen(str1)+strlen(str2)-1];
	strcpy(result,str1);
	strcat(result,str2);
	cout<<"the first str is "<<str1<<endl;
	cout<<"the second str is "<<str2<<endl;
	cout<<"the result str is "<<result<<endl;
	return 0;
}