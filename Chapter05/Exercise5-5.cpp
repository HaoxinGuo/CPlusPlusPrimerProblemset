#include<iostream>
using namespace std;
int main(){
	int grade;
	cout<<"Please enter the score:"<<endl;
	cin>>grade;
	if(grade<0||grade>100){
		cout<<"The Score is wrong"<<endl;
		return -1;
	}
	if(grade==100){
		cout<<"A++"<<endl;
		return -1;
	}
	if(grade<60){
		cout<<"F"<<endl;
		return -1;
	}
	int iU = grade /10;
	int iT = grade % 10;
	string score,level,lettergrade;
	if(iU ==9)
		score = "A";
	else if(iU==8)
		score = "B";
	else if(iU ==7)
		score = "C";
	else
		score = "D";
	//处理级别
	if(iT<3)
		level = "-";
	else if(iT>7)
		level = "+";
	else
		level = "";
	lettergrade = score+level;
	cout<<"The grade is:"<<lettergrade<<endl;
	return 0;
}