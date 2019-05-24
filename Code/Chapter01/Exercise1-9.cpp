// C++primer¿ÎºóÁ·Ï°ÌâÁ·Ï° 1.9
#include<iostream>
using namespace std;
int main(){
	int i=50;
	int sum =0;
	while(i<100){
		sum += i;
		i++;
	}
	cout<<"the sum  of 50 ~ 100 is " << sum << endl;
	int t;
	cin >> t;
	return 0;
}