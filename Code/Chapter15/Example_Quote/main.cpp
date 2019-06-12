
#include"Quote.h"
#include"Disc_quote.h"
#include"Bulk_quote.h"
#include<vector>
#include"Basket.h"
/*
double print_total(ostream &os, const Quote &item, size_t n)
{
	// 根据传入item形参的对象类型调用Quote::net_price
	// 或者Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // 调用Quote::isbn
		<< " # sold: " << n << " total due: " << ret << endl;

	return ret;
}
*/


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




void func2()
{
	// 使用拷贝/移动的版本插入
	Basket bsk;
	bsk.add_item(make_shared<Quote>("0-201-70353-X", 10));
	bsk.add_item(make_shared<Bulk_quote>("0-201-70354-X", 10, 2, 0.5));
	bsk.add_item(make_shared<Bulk_quote>("0-201-70354-X", 10, 2, 0.5));

	bsk.total_receipt(cout);
}




int main() {
	//func();

	/*
		vector<Quote> basket1;
	basket1.push_back(Quote("0-X-1", 50));
	basket1.push_back(Bulk_quote("0-X-1", 50,10,0.25));
	double  sum = 0;
	for (auto &a : basket1) {
		sum += a.net_price(10);
	}
	cout << sum << endl;
	*/


	//练习28
	/*
		vector<shared_ptr<Quote>> basket;
	basket.push_back(make_shared<Quote>("0-X-1", 50));
	basket.push_back(make_shared<Bulk_quote>("0-X-1", 50,10,0.25));
	sum = 0;
	for (auto &a : basket) {
		sum += a->net_price(10);
	}
	cout << sum << endl;
	*/



	//练习30
	func2();

	char ch;
	cin >> ch;
	return 0;
}