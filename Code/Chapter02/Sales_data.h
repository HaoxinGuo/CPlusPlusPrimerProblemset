// C++primer课后练习题练习 2.41
// 重写Sales_data类
#ifndef SALES_DATA_H_INCLUDE
#define SALES_DATA_H_INCLUDE

#include<iostream>
#include<string>
using namespace std;
class Sales_data {
	//友元函数
	friend ostream& operator << (ostream&,Sales_data&);
	friend istream& operator >> (istream&, Sales_data&);
	friend bool operator == (const Sales_data&,const Sales_data&);
	friend bool operator < (const Sales_data&,const Sales_data&);
public://构造函数
	Sales_data(){};
	Sales_data(const string &book) :bookNo(book) {};
	Sales_data(istream &is) { is >> *this; };
public:
	Sales_data& operator +=(const Sales_data&);
	string isbn() const { return bookNo; };
private:
	string bookNo;			//书籍编号
	unsigned units_sold; //销售量
	double sellingprice;//原始价格
	double saleprice; //销售价格
	double discount; //折扣
};
inline bool compareIsbn(const Sales_data &lhs,const Sales_data &rhs){
	return lhs.isbn()==rhs.isbn();
}

inline bool operator ==(const Sales_data &lhs,const Sales_data &rhs){
	return lhs.isbn()==rhs.isbn()&&
	lhs.units_sold==rhs.units_sold&&
	lhs.saleprice==rhs.saleprice&&
	lhs.sellingprice==rhs.sellingprice;
}

inline bool operator !=(const Sales_data &lhs,const Sales_data &rhs){
	return !(rhs==lhs);//基于==给出！=的定义
}

Sales_data operator +(const Sales_data& lhs,const Sales_data& rhs){
	Sales_data ret(lhs);//把lhs的内容拷贝到临时变量ret中
	ret +=rhs;//把rhs加入到变量中
	return ret;//返回ret
}

Sales_data&  Sales_data::operator += (const Sales_data& rhs) {
	units_sold += rhs.units_sold;
	saleprice = (saleprice * units_sold + rhs.units_sold * rhs.saleprice) / (units_sold + rhs.units_sold);
	if (sellingprice != 0)
		discount = saleprice / sellingprice;
	return *this;
}

ostream& operator <<(ostream& out,Sales_data& book){
	out << book.isbn()<<" "<<book.units_sold<<" "<<book.sellingprice<<" "<<book.saleprice<<endl;
	return out;
}
istream& operator >> (istream& in, Sales_data& book) {
	in >> book.bookNo >> book.units_sold >> book.sellingprice >> book.saleprice;
	if (in && book.sellingprice != 0)
		book.discount = book.saleprice / book.sellingprice;
	else
		book = Sales_data();//输入错误重新输入；
	return in;
}
#endif //SALES_DATA_H_INCLUDE