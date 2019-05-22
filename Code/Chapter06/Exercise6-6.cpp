#include<iostream>

using namespace std;

//6.6
double Mysum(double val1,double val2){
	double sum =val1+val2;
	static int cnt = 0;
	++cnt;
	cout<<"该函数已经累计执行"<<cnt<<"次。"<<endl;
	return sum;
}
//6.7
unsigned myCnt(){
	static unsigned cnt = -1;
	++cnt;
	return cnt;
}
int main(){
	cout<<"请输入两个数："<<endl;
	double val1,val2;
	while(cin>>val1>>val2){
		cout<<"val1 + val2 = "<<Mysum(val1,val2)<<endl;
		cout<<"请输入两个数："<<endl;
	}
	return 0;
}