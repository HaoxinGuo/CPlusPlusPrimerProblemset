#include<iostream>
#include<string>

class Sales_data {
	friend std::istream &read1(std::istream &is, Sales_data &item);
	friend Sales_data add1(const Sales_data &lhs, const Sales_data &rhs);
	friend std::ostream &print1(std::ostream &os, Sales_data &item);
	friend std::istream& operator >>(std::istream &is,Sales_data &item);
	friend std::ostream& operator <<(std::ostream &os,const Sales_data &item);
private:
	std::string BookNo;
	unsigned Units_sold = 0;
	double sellingprice = 0.0;
	double saleprice = 0.0;
	double discount = 0.0;
public:
	Sales_data()=default;
	Sales_data(const std::string &book):BookNo(book){};
	Sales_data(const std::string &book,const unsigned num,const double sell,const double sale);
	Sales_data(std::istream &is);
	std::string isbn() const { return BookNo; };
	Sales_data& combine(const Sales_data &rhs) {
		Units_sold += rhs.Units_sold;
		saleprice = (rhs.Units_sold * rhs.saleprice + Units_sold * saleprice) / (rhs.Units_sold + Units_sold);
		if (sellingprice != 0)
			discount = saleprice / sellingprice;
		return *this;
	};
};
Sales_data::Sales_data(const std::string &book,const unsigned num,
						const double sell,const double sale){
	BookNo = book;
	Units_sold = num;
	sellingprice = sell;
	saleprice = sale;
	if(sellingprice!=0)
		discount = saleprice/sellingprice;
}

Sales_data::Sales_data(std::istream &is){
	is >> *this;
}

std::istream& operator >>(std::istream &is,Sales_data &item){
	is>>item.BookNo>>item.Units_sold>>item.sellingprice>>item.saleprice;
	if(item.sellingprice!=0)
		item.discount = item.saleprice/item.sellingprice;
	return is;
}

std::ostream& operator <<(std::ostream &os,const Sales_data &item){
	os<<item.isbn()<<" "<<item.Units_sold<<" "<<item.sellingprice<<" "<<item.saleprice<<" " <<item.discount;
	return os;
}

Sales_data add1(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = rhs;
	sum.combine(lhs);
	return sum;
}

std::istream &read1(std::istream &is, Sales_data &item) {
	is >> item.BookNo >> item.Units_sold >> item.sellingprice >> item.saleprice;
	return is;
}

std::ostream &print1(std::ostream &os, Sales_data &item) {
	os << item.isbn() << " " << item.Units_sold << " "
		<< item.sellingprice << " " << item.saleprice << " " << item.discount << " ";
	return os;
}

