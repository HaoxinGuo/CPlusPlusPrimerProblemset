#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
//c ����ַ��� strlen strcpy strcat
int main(){
	int val[3][4]={0,1,2,3,
					4,5,6,7,
					8,9,10,11};
	cout<<"Use ��Χfor��䣺"<<endl;
	for(int (&row)[4]:val){
		for(int &col:row)
			cout<<col<<" ";
		cout<<endl;
	}
	cout<<"ʹ���±������"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++)
			cout<<val[i][j]<<" ";
	cout<<endl;
	}
	cout<<endl<<"ʹ��ָ��"<<endl;
	for(int (*p)[4] = val ; p!=val+3;p++){
		for(int *q=*p;q!=*p+4;q++)
			cout<<*q<<" ";	
	cout<<endl;
	}
	return 0;
}