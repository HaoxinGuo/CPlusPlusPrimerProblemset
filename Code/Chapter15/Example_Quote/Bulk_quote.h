#pragma once
#include "Disc_quote.h"
class Bulk_quote :
	public Disc_quote
{
public:
	Bulk_quote();
	/*
	Bulk_quote(const string &book, double price, size_t qty, double disc) :
		Disc_quote(book, price, qty, disc) {
		cout << "Bulk_quote(const string &book, double price, size_t qty, double disc)" << endl;
	};
	*/
	using Disc_quote::Disc_quote;
	Bulk_quote(const Bulk_quote&);
	Bulk_quote(Bulk_quote&&);
	Bulk_quote& operator=(const Bulk_quote&);
	Bulk_quote& operator=(Bulk_quote&&);
	~Bulk_quote();
	double net_price(size_t) const override;
};

