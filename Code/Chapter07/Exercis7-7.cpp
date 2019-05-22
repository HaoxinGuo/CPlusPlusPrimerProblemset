#include"Sales_data.h"
using namespace std;
Sales_data add1(const Sales_data &lhs, const Sales_data &rhs) {
	Sales_data sum = rhs;
	sum.combine(lhs);
	return sum;
}

std::istream &read1(std::istream &is, Sales_data &item) {
	is >> item.BookNo >> item.Units_sold >> item.sellingprice >> item.saleprice;
	return is;
}

std::ostream &print1(std::ostream &os, Sales_data &item) {
	os << item.isbn() << " " << item.Units_sold << " "
		<< item.sellingprice << " " << item.saleprice << " " << item.discount << " ";
	return os;
}


int main() {
	cout << "请输入交易记录：" << endl;
	Sales_data total;
	if (read1(cin, total)) 
	{
		Sales_data trans;
		while (read1(cin, trans)) {
			if (total.isbn() == trans.isbn())
				total = add1(total, trans);
			else {
				print1(cout, total);
				cout << endl;
				total = trans;
			}
		}
		print1(cout, total);
		cout << endl;
	}
	else 
	{
		cout << "No data" << endl;
		return -1;
	}
	return 0;
}