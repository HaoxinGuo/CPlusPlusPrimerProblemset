//练习15.20：编写代码检验你对前面两题的回答是否正确。
#include<iostream>
#include<string>

using namespace std;

class Base {
public:
	void pub_mem() const {};
protected:
	int prot_mem;
private:
	char priv_mem;
};

struct Pub_derv :public Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) {
		b = *this;
		cout << "Pub_derv" << endl;
	}
};

struct Prot_derv :protected Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) {
		b = *this;
		cout << "Prot_derv" << endl;
	}
};

struct Priv_derv :private Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) {
		b = *this;
		cout << "Priv_derv" << endl;
	}
};

struct Derived_from_public :public Base {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) {
		b = *this;
		cout << "Derived_from_public" << endl;
	}
};

struct Derived_from_protected :protected Base {
	int use_base() { return prot_mem; }
	void memfcn(Base &b) {
		b = *this;
		cout << "Derived_from_protected" << endl;
	}
};


struct Derived_from_private :private Base {
	int f() { return prot_mem; }
	void memfcn(Base &b) {
		b = *this;
		cout << "Derived_from_private" << endl;
	}
};



int main() {
	Pub_derv d1;
	Priv_derv d2;
	Prot_derv d3;
	Derived_from_public dd1;
	Derived_from_private dd2;
	Derived_from_protected dd3;
	Base base;
	Base *p = new Base;
	p = &d1;	// d1的类型是Pub_Derv，合法
	//p = &d2;		// d2的类型是Priv_Derv，非法，非公有继承
	//p = &d3;		// d3的类型是Prot_Derv，非法，非公有继承
	p = &dd1;		// dd1的类型是Derived_from_Public，合法
	//p = &dd2;		// dd2的类型是Derived_from_Private，非法，非公有继承
	//p = &dd3;		// dd3的类型是Derived_from_Protected，非法，非公有继承
	d1.memfcn(base);
	d2.memfcn(base);
	d3.memfcn(base);
	dd1.memfcn(base);
	dd2.memfcn(base);
	dd3.memfcn(base);
	char ch;
	cin >> ch;
	return 0;
}