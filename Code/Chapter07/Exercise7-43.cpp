#include"Person.h"

using namespace std;

class Nodefault{
public:
	Nodefault(int i){
		val = i;
	}
	int val;
};

class C{
public:
	Nodefault nd;
	C(int i =0):nd(i){}
};



int main() {
	C c;
	cout<<c.nd.val<<endl;
	return 0;
}