// 练习15.6：将Quote和Bulk_quote的对象传递给15.2.1节（第529页）练习中的
// print_total函数，检查该函数是否正确。

#include <iostream>
#include<string>

using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(string &book, double sale_price) :bookNo(book), price(sale_price) {};
	string isbn() const { return bookNo; };
	virtual double net_price(size_t n) const { return n * price; };
	virtual void debug() const {
		cout << "bookNo: "<< bookNo << " Price: "<< price<<endl;
	}
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

ostream& print_total(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "bookNo is " << item.isbn() << " #sold is " << n << "total due " << ret << endl;
	return os;
}



int main() {
	string book = "0-201-70353-X";
	Quote base(book, 5);
	print_total(cout,base,20);
	base.debug();
	return 0;
}
