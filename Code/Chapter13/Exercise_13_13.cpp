// 练习13.13

#include <iostream>
#include <string>
#include<vector>

using namespace std;

class X{
public:
	X(){cout<<"X()"<<endl;}
	X(const X&){cout<< "X(const X&)"<<endl;}
	~X(){cout<< "~X()"<<endl;}
	X& operator=(const X &rh){
		i = rh.i;
		j = rh.j;
		cout<< "X& operator="<<endl;
		return *this;}
	
private:
	int i;
	double j;
};

void f1(X){
	
}

void f2(X&){
	
}

int main()
{
	/*&
	X a;
	f1(a);
	f2(a);
	X b;
	b = a;
	auto px = new X();
	delete px;
	*/
	std::vector<X> x_vec;
	//x_vec.emplace_back();
	x_vec.push_back(X());
	return 0;
}