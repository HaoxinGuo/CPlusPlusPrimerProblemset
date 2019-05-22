#include<iostream>
#include<string>

class Sales_data {
	friend std::istream &read1(std::istream &is, Sales_data &item);
	friend Sales_data add1(const Sales_data &lhs, const Sales_data &rhs);
	friend std::ostream &print1(std::ostream &os, Sales_data &item);
private:
	std::string BookNo;
	unsigned Units_sold;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
public:
	std::string isbn() { return BookNo; };
	Sales_data& combine(const Sales_data &rhs) {
		Units_sold += rhs.Units_sold;
		saleprice = (rhs.Units_sold * rhs.saleprice + Units_sold * saleprice) / (rhs.Units_sold + Units_sold);
		if (sellingprice != 0)
			discount = saleprice / saleprice;
		return *this;
	};
};