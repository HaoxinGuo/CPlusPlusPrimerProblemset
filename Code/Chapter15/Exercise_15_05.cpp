// 练习15.5：定义你自己的Bulk_quote类。


#include <iostream>
#include <string>

using namespace std;

class Quote {
public:
	Quote() = default;
	Quote(string &book, double sale_price) :bookNo(book), price(sale_price) {};
	string isbn() const { return bookNo; };
	virtual double net_price(size_t n) const { return n * price; };
	virtual ~Quote() = default;
private:
	string bookNo;
protected:
	double price = 0.0;
};

class Bulk_Quote:public Quote{
public:
	Bulk_Quote() = default;
	Bulk_Quote(string &book,double p,double dis,size_t qty):
			Quote(book,p),discount(dis),min_qty(qty){};
	double net_price(size_t n) const override {
		if(n>min_qty)
			return n*(1-discount)*price;
		else
			return n*price;
	};
	~Bulk_Quote() = default;
private:
	string bookNo;
protected:
	double discount = 0.0;
	size_t min_qty = 0;
};

ostream& print_total(ostream &os, const Quote &item, size_t n) {
	double ret = item.net_price(n);
	os << "bookNo is " << item.isbn() << " #sold is " << n << "total due " << ret << endl;
	return os;
}







int main(){
	Quote Book1;
	Bulk_Quote Bool2;
	return 0;
}



