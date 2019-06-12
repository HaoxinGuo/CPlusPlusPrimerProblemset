#include "Basket.h"



// ���㲢��ӡ���۸���������ĳ���鼮���õķ���
double print_total(ostream &os, const Quote &item, size_t n)
{
	// ���ݴ���item�βεĶ������͵���Quote::net_price
	// ����Bulk_quote::net_price
	double ret = item.net_price(n);
	os << "ISBN: " << item.isbn() // ����Quote::isbn
		<< " # sold: " << n << " total due: " << ret << endl;

	return ret;
}


double Basket::total_receipt(std::ostream & os) const
{

	double sum = 0.0;	// ����ʵʱ��������ܼ۸�
	// iterָ��ISBN��ͬ��һ��Ԫ���еĵ�һ��
	// upper_bound����һ�����������õ�����ָ������Ԫ�ص�β��λ��
	for (auto iter = items.cbegin(); iter != items.cend(); iter = items.upper_bound(*iter)) {
		// ����֪���ڵ�ǰ��Basket��������һ���ؼ���Ԫ��
		// ��ӡ���鼮��Ӧ����Ŀ
		sum += print_total(os, **iter, items.count(*iter));
	}
	os << "Total Sale: " << sum << endl; // ��ӡ���յ��ܼ۸�
	return sum;
}
