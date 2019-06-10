#pragma once
#include "Quote.h"
class Disc_quote :
	public Quote
{
public:
	Disc_quote();
	Disc_quote(const string &book, double price, size_t qty, double disc) :Quote(book, price), quantity(qty), discount(disc) {
		cout << "Disc_quote(const string &book, double price, size_t qty, double disc)" << endl;
	};
	Disc_quote(const Disc_quote&);
	Disc_quote(Disc_quote&&);
	Disc_quote& operator=(const Disc_quote&);
	Disc_quote& operator=(Disc_quote&&);
	virtual double net_price(size_t n) const = 0;
	void debug();
	~Disc_quote();
protected:
	double discount = 0.0;//表示折扣的小数值
	size_t quantity = 0;//表示折扣适用的购买量
};

