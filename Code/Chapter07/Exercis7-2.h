#ifndef SALES_DATA_INCLUDED
#define SALES_DATA_INCLUDED

#include<iostream>
#include<string>

class Sales_data{
	private:
		string BookNo;
		unsigned Units_sold;
		double sellingprice = 0.0;
		double saleprice = 0.0;
		double discount = 0.0;
	public:
		string isbn() {return BookNo;};
		Sales_data& combine(const Sales_data &rhs){
			Units_sold += rhs.Units_sold;
			saleprice = (rhs.Units_sold * rhs.saleprice + Units_sold * saleprice)/(rhs.Units_sold + Units_sold);
			if(sellingprice!=0)
				discount = saleprice / saleprice;
			return *this;
		}
#endif
Sales_data add(const Sales_data &lhs,const Sales_data &rhs){
	Sales_data sum = rhs;
	sum.combine(lhs);
	return sum;
}

std::istream &read(std::istream &is,Sales_data &item){
	is >> item.BookNo >> item.Units_sold >> item.sellingprice>>item.saleprice;
	return is;
}

std::ostream &print(std::ostream &os,Sales_data &item){
	os<<item.isbn()<<" "<<item.Units_sold<<" "
	<<item.sellingprice<<" "<<item.saleprice<<" "<<item.discount<<" ";
	return os;
}



