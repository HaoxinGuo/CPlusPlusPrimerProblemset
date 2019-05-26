//Á·Ï°11-11


#include <iostream>
#include <set>
#include"Sales_data.h"

using namespace std;

typedef bool (*compare_func)(const Sales_data &lhs, const Sales_data &rhs);

bool compareIsbn(const Sales_data &lhs, const Sales_data &rhs)
{
	return lhs.isbn() < rhs.isbn();
}

int main()
{
	multiset<Sales_data, compare_func> bookstore(compareIsbn);

	return 0;
}