#include"Person.h"

using namespace std;

std::istream &read(std::istream &is, Person &per) {
	is >> per.strname >> per.straddress;
	return is;
}

std::ostream &print(std::ostream &os, Person &per) {
	os << per.getname() << " " << per.getadress();
	return os;
}


int main() {
	Person per;
	Person Per1("guohaoxin","802");
	//read(cin,per);
	print(cout,Per1);
	return 0;
}