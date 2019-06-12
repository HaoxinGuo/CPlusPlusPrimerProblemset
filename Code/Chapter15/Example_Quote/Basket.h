#pragma once
#include "Quote.h"
#include <iterator>
#include <memory>
#include <set>
//#include "Basket.h"
//#include "Disc_quote.h"


class Basket
{
public:
	// Basketʹ�úϳɵ�Ĭ�Ϲ��캯���Ϳ������Ƴ�Ա
	void add_item(const std::shared_ptr<Quote> &sale) { items.insert(sale); }
	/*
		void add_item(const Quote &sale)
	{
		items.insert(std::shared_ptr<Quote>(sale));
	}

	void add_item(Quote &&sale)
	{
		items.insert(std::shared_ptr<Quote>(std::move(sale)));
	}
	
	*/




	double total_receipt(std::ostream&)const;
private:
	static bool compare(const std::shared_ptr<Quote> &lhs, const std::shared_ptr<Quote> &rhs) {
		return lhs->isbn() < rhs->isbn();
	}
	std::multiset<std::shared_ptr<Quote>, decltype(compare)*> items{ compare };
};


