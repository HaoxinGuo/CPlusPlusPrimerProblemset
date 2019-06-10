#pragma once
#include<iostream>
#include<string>

using namespace std;

class Quote
{
	//friend double print_total(ostream &os, const Quote &item, size_t n);
public:
	Quote();//默认构造函数
	Quote(const string &book, double sales_price) :bookNo(book), price(sales_price) {
		cout << "Quote(const string &book, double sales_price)" << endl;
	};//构造函数
	Quote(const Quote&);		//拷贝函数
	Quote(Quote&&);				//移动构造函数
	Quote& operator=(const Quote&);			//拷贝赋值函数
	Quote& operator=(Quote && );	//移动赋值函数
	string isbn() const { return bookNo; };
	virtual double net_price(size_t) const;//计算价格
	virtual void debug();//显示数据
	virtual ~Quote();
private:
	string bookNo;
protected:
	double price = 0.0;
};
