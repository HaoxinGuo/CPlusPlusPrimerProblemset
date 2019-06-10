#include "Bulk_quote.h"



Bulk_quote::Bulk_quote()
{
}


Bulk_quote::Bulk_quote(const Bulk_quote &bq):Disc_quote(bq)
{
	cout << "Bulk_quote::Bulk_quote" << endl;
}

Bulk_quote::Bulk_quote(Bulk_quote &&bq):Disc_quote(std::move(bq))
{
	cout << "Bulk_quote::Bulk_quote(Bulk_quote &&bq)" << endl;
}

Bulk_quote & Bulk_quote::operator=(const Bulk_quote &bq)
{
	Disc_quote::operator=(bq);
	cout << "Bulk_quote::operator=(const Bulk_quote &bq)" << endl;
	return *this;
	// TODO: 在此处插入 return 语句
}

Bulk_quote & Bulk_quote::operator=(Bulk_quote &&bq)
{
	Disc_quote::operator=(std::move(bq));
	cout <<" Bulk_quote::operator=(Bulk_quote &&bq)" << endl;
	return *this;
	// TODO: 在此处插入 return 语句
}

Bulk_quote::~Bulk_quote()
{
	cout << "Bulk_quote::~Bulk_quote()" << endl;

}

double Bulk_quote::net_price(size_t n) const 
{
	if (n < quantity)
		return n * price;
	else
		return ((n - quantity) * price + quantity * (1 - discount) * price);
}
