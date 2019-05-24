// C++primer�κ���ϰ����ϰ 2.41
// ��дSales_data��
#ifndef SALES_DATA_H_INCLUDE
#define SALES_DATA_H_INCLUDE

#include<iostream>
#include<string>
using namespace std;
class Sales_data {
	//��Ԫ����
	friend ostream& operator << (ostream&,Sales_data&);
	friend istream& operator >> (istream&, Sales_data&);
	friend bool operator == (const Sales_data&,const Sales_data&);
	friend bool operator < (const Sales_data&,const Sales_data&);
public://���캯��
	Sales_data(){};
	Sales_data(const string &book) :bookNo(book) {};
	Sales_data(istream &is) { is >> *this; };
public:
	Sales_data& operator +=(const Sales_data&);
	string isbn() const { return bookNo; };
private:
	string bookNo;			//�鼮���
	unsigned units_sold; //������
	double sellingprice;//ԭʼ�۸�
	double saleprice; //���ۼ۸�
	double discount; //�ۿ�
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
	return !(rhs==lhs);//����==������=�Ķ���
}

Sales_data operator +(const Sales_data& lhs,const Sales_data& rhs){
	Sales_data ret(lhs);//��lhs�����ݿ�������ʱ����ret��
	ret +=rhs;//��rhs���뵽������
	return ret;//����ret
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
		book = Sales_data();//��������������룻
	return in;
}
#endif //SALES_DATA_H_INCLUDE