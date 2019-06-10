#include "Disc_quote.h"



Disc_quote::Disc_quote()
{
	cout << "Disc_quote::Disc_quote()" << endl;
}

Disc_quote::Disc_quote(const Disc_quote &dq):Quote(dq),discount(dq.discount),quantity(dq.quantity)
{
	cout << "Disc_quote::Disc_quote(const Disc_quote &dq)" << endl;
}

Disc_quote::Disc_quote(Disc_quote &&dq):Quote(std::move(dq)),quantity(dq.quantity),discount(dq.discount)
{
	cout << "isc_quote::Disc_quote(Disc_quote &&dq)" << endl;
}

Disc_quote & Disc_quote::operator=(const Disc_quote &dq)
{
	Quote::operator=(dq);
	discount = dq.discount;
	quantity = dq.quantity;
	cout << "Disc_quote & Disc_quote::operator=(const Disc_quote &dq)" << endl;
	return *this;
	// TODO: 在此处插入 return 语句
}

Disc_quote & Disc_quote::operator=(Disc_quote &&dq)
{
	Quote::operator=(dq);
	discount = dq.discount;
	quantity = dq.quantity;
	cout << "Disc_quote & Disc_quote::operator=(Disc_quote &&dq)" << endl;
	return *this;
	// TODO: 在此处插入 return 语句
}


void Disc_quote::debug()
{
	Quote::debug();
	cout << "quantity " << quantity << " discount " <<  discount <<endl;
}

Disc_quote::~Disc_quote()
{
	cout << "Disc_quote::~Disc_quote()" << endl;
}
