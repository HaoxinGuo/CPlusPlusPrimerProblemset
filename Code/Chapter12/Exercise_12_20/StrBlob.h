#ifndef __STR_BLOB_H__
#define __STR_BLOB_H__

#include <vector>
#include <string>
#include <initializer_list>
#include <memory>

#include "StrBlobPtr.h"
#include "ConstStrBlobPtr.h"

class StrBlob {
	friend class StrBlobPtr;
	friend class ConstStrBlobPtr;

public:
	typedef std::vector<std::string>::size_type size_type;

	StrBlob() : data(std::make_shared<std::vector<std::string>>()) {}
	StrBlob(std::initializer_list<std::string> il) :
		data(std::make_shared<std::vector<std::string>>(il)) {}

	inline size_type size() const { return data->size(); }
	inline bool empty() const { return data->empty(); }

	// ��Ӻ�ɾ��Ԫ��
	inline void push_back(const std::string &t) { data->push_back(t); }
	inline void pop_back();

	// Ԫ�ط���
	inline std::string& front();
	inline std::string& back();
	inline const std::string& front() const;
	inline const std::string& back() const;

	// ����ָ����Ԫ�غ�β��Ԫ�ص�StrBlobPtr
	inline StrBlobPtr begin() { return StrBlobPtr(*this); }
	inline StrBlobPtr end() { return StrBlobPtr(*this, data->size()); }

	inline ConstStrBlobPtr begin() const { return ConstStrBlobPtr(*this); }
	inline ConstStrBlobPtr end() const { return ConstStrBlobPtr(*this, data->size()); }

private:
	std::shared_ptr<std::vector<std::string>> data;

	// ���data[i]���Ϸ����׳�һ���쳣
	inline void check(size_type i, const std::string &msg) const;
};

void StrBlob::check(size_type i, const std::string &msg) const
{
	if (i >= data->size())
		throw std::out_of_range(msg);
}

std::string& StrBlob::front()
{
	// ���vectorΪ�գ�check���׳�һ���쳣
	check(0, "front on empty StrBlob");
	return data->front();
}

std::string& StrBlob::back()
{
	check(0, "back on empty StrBlob");
	return data->back();
}

void StrBlob::pop_back()
{
	check(0, "pop_back on empty StrBlob");
	return data->pop_back();
}

const std::string& StrBlob::front() const
{
	check(0, "front on empty StrBlob");
	return data->front();
}

const std::string& StrBlob::back() const
{
	check(0, "back on empty StrBlob");
	return data->back();
}

#endif // __STR_BLOB_H__
