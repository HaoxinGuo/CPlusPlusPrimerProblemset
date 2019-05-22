#include<iostream>
#include<ctime>
#include<cstdlib>
#include<cstring>
#include<vector>
using namespace std;
//c 风格字符串 strlen strcpy strcat
int main(){
	int val[3][4]={0,1,2,3,
					4,5,6,7,
					8,9,10,11};
	cout<<"Use 范围for语句："<<endl;
	for(int (&row)[4]:val){
		for(int &col:row)
			cout<<col<<" ";
		cout<<endl;
	}
	cout<<"使用下标运算符"<<endl;
	for(int i=0;i<3;i++){
		for(int j=0;j<4;j++)
			cout<<val[i][j]<<" ";
	cout<<endl;
	}
	cout<<endl<<"使用指针"<<endl;
	for(int (*p)[4] = val ; p!=val+3;p++){
		for(int *q=*p;q!=*p+4;q++)
			cout<<*q<<" ";	
	cout<<endl;
	}
	return 0;
}