// C++primer课后练习题练习 1.11
#include<iostream>
using namespace std;
int main(){
	cout<<"Please Enter two number V1 V2" <<endl;
	int V1, V2;
	cin >> V1 >> V2;
	if (V1>V2)
		while(V1 >= V2){
			cout<< V1 << " ";
			V1--;
		}
	else if(V1 < V2)
		while(V1 <= V2){
			cout<<V1<<" ";
			V1++;
		}
	else
		cout<< V1<< endl;
}