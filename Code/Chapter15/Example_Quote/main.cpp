
#include"Quote.h"
#include"Disc_quote.h"
#include"Bulk_quote.h"


double print_total(ostream &os, const Quote &item, size_t n)
{
	// 根据传入item形参的对象类型调用Quote::net_price
	// 或者Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // 调用Quote::isbn
		<< " # sold: " << n << " total due: " << ret << endl;

	return ret;
}

void func() {
	Quote item("0-1-X", 10);
	Quote item4;
	item4 = item;
	//item4.debug();
	//item.debug();
	//print_total(cout, item, 10);
	Bulk_quote item2("0-1-X", 10, 5, 0.5);
	//item2.debug();
	Bulk_quote item5;

	item5 = item2;

	//print_total(cout, item5, 10);
	//print_total(cout, item2, 10);
	//Disc_quote item3;
}



int main() {
	func();
	char ch;
	cin >> ch;
	return 0;
}