#include "Strblob.h"



Strblob::Strblob():data(make_shared<vector<string>>())
{
}

Strblob::Strblob(initializer_list<string> i1): data(make_shared<vector<string>>(i1))
{
}

void Strblob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

string & Strblob::front()
{
	check(0, "front on empty StrBlob");
	return data->front();
	// TODO: 在此处插入 return 语句
}

const string & Strblob::front() const
{
	check(0, "frond on empty StrBlob");
	return data->front();
	// TODO: 在此处插入 return 语句
}

string & Strblob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
	// TODO: 在此处插入 return 语句
}

const string & Strblob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
	// TODO: 在此处插入 return 语句
}

Strblob::~Strblob()
{
}

void Strblob::check(size_type i, const std::string & msg) const
{
	if (i >= data->size())
		throw out_of_range(msg);
}
