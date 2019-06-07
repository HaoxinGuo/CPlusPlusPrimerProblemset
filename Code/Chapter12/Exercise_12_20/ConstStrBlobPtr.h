#ifndef __CONST_STR_BLOB_PTR_H__
#define __CONST_STR_BLOB_PTR_H__

#include <memory>
#include <vector>
#include <string>

class StrBlob;

class ConstStrBlobPtr
{
public:
	ConstStrBlobPtr() : curr(0) {}
	ConstStrBlobPtr(const StrBlob &a, size_t sz = 0);

	const std::string &deref() const;
	ConstStrBlobPtr &incr(); // ǰ׺����

	const std::string& operator*() const;
	const std::string* operator->() const;

private:
	// �����ɹ���check����һ��ָ��vector��shared_ptr
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr; // ����һ��weak_ptr����ζ�ŵײ�vector���ܻᱻ����
	std::size_t curr; // �������еĵ�ǰλ��
};


inline std::shared_ptr<std::vector<std::string>>
ConstStrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();	// vector��������

	if (!ret)
	{
		throw std::runtime_error("unbound ConstStrBlobPtr");
	}

	if (i >= ret->size())
	{
		throw std::out_of_range(msg);
	}

	return ret;
}

inline const std::string & ConstStrBlobPtr::deref() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr]; // (*p)�Ƕ�����ָ���vector
}

// ǰ׺���������ص�����Ķ��������
inline ConstStrBlobPtr & ConstStrBlobPtr::incr()
{
	check(curr, "increment past end of ConstStrBlobPtr");
	++curr;
	return *this;
}

inline const std::string& ConstStrBlobPtr::operator*() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr];
}

inline const std::string* ConstStrBlobPtr::operator->() const
{
	return &operator*();
}

#endif
