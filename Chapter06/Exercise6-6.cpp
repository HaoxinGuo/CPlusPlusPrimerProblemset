#include<iostream>

using namespace std;

//6.6
double Mysum(double val1,double val2){
	double sum =val1+val2;
	static int cnt = 0;
	++cnt;
	cout<<"�ú����Ѿ��ۼ�ִ��"<<cnt<<"�Ρ�"<<endl;
	return sum;
}
//6.7
unsigned myCnt(){
	static unsigned cnt = -1;
	++cnt;
	return cnt;
}
int main(){
	cout<<"��������������"<<endl;
	double val1,val2;
	while(cin>>val1>>val2){
		cout<<"val1 + val2 = "<<Mysum(val1,val2)<<endl;
		cout<<"��������������"<<endl;
	}
	return 0;
}