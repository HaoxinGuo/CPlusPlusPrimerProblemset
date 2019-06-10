#include "Quote.h"



Quote::Quote()
{
	cout << "Quote::Quote()" << endl;
}

Quote::Quote(const Quote &q):bookNo(q.bookNo),price(q.price)
{
	cout << "Quote::Quote(const Quote &q)" << endl;
}

Quote::Quote(Quote &&q):bookNo(std::move(q.bookNo)), price(q.price)
{
	cout << "uote(Quote &&q)" << endl;
}

Quote & Quote::operator=(const Quote &q)
{
	bookNo = q.bookNo;
	price = q.price;
	cout << "Quote::operator=" << endl;
	return *this;
	// TODO: 在此处插入 return 语句
}

Quote & Quote::operator=(Quote &&q)
{
	bookNo = q.bookNo;
	price = q.price;
	return *this;
	// TODO: 在此处插入 return 语句
}


double Quote::net_price(size_t n) const 
{
	return n * price;
}

void Quote::debug()
{
	cout << "bookNo:" << bookNo << " price " << price << endl;
}

Quote::~Quote()
{
	cout << "Quote::~Quote()" << endl;
}

