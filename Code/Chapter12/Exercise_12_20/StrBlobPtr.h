#ifndef __STR_BLOB_PTR_H__
#define __STR_BLOB_PTR_H__

#include <memory>
#include <vector>
#include <string>

class StrBlob;

class StrBlobPtr
{
	friend bool operator==(const StrBlobPtr &rhs, const StrBlobPtr &lhs);
	friend bool operator!=(const StrBlobPtr &rhs, const StrBlobPtr &lhs);
	friend bool operator<(const StrBlobPtr &rhs, const StrBlobPtr &lhs);
	friend StrBlobPtr operator+(const StrBlobPtr &rhs, size_t n);
	friend StrBlobPtr operator-(const StrBlobPtr &rhs, size_t n);

public:
	StrBlobPtr() : curr(0) {}
	StrBlobPtr(StrBlob &a, size_t sz = 0);

	std::string &deref() const;
	StrBlobPtr &incr(); // ǰ׺����

	std::string& operator[](size_t);
	const std::string& operator[](size_t) const;

	StrBlobPtr& operator++();
	StrBlobPtr& operator--();
	StrBlobPtr operator++(int);
	StrBlobPtr operator--(int);
	std::string& operator*() const;
	std::string* operator->() const;

private:
	// �����ɹ���check����һ��ָ��vector��shared_ptr
	std::shared_ptr<std::vector<std::string>>
		check(std::size_t, const std::string&) const;

	std::weak_ptr<std::vector<std::string>> wptr; // ����һ��weak_ptr����ζ�ŵײ�vector���ܻᱻ����
	std::size_t curr; // �������еĵ�ǰλ��
};


inline std::shared_ptr<std::vector<std::string>>
StrBlobPtr::check(std::size_t i, const std::string& msg) const
{
	auto ret = wptr.lock();	// vector��������

	if (!ret)
	{
		throw std::runtime_error("unbound StrBlobPtr");
	}

	if (i >= ret->size())
	{
		throw std::out_of_range(msg);
	}

	return ret;
}

inline std::string & StrBlobPtr::deref() const
{
	auto p = check(curr, "deference past end");
	return (*p)[curr]; // (*p)�Ƕ�����ָ���vector
}

inline std::string& StrBlobPtr::operator[](size_t n)
{
	auto p = check(n, "out of range");
	return (*p)[n];
}

inline const std::string& StrBlobPtr::operator[](size_t n) const
{
	auto p = check(n, "out of range");
	return (*p)[n];
}

inline StrBlobPtr& StrBlobPtr::operator++()
{
	// ���curr�Ѿ�ָ����β��λ�ã����޷�������
	check(curr, "increment past end of StrBlobPtr");
	++curr;			// ��curr�ڵ�ǰ״̬����ǰ�ƶ�һ��Ԫ��
	return *this;
}

inline StrBlobPtr& StrBlobPtr::operator--()
{
	// ���curr��0��������ݼ���������һ����Ч�±�
	--curr;			// ��curr�ڵ�ǰ״̬������ƶ�һ��Ԫ��
	check(curr, "decrement past begin of StrBlobPtr");
	return *this;
}

inline StrBlobPtr StrBlobPtr::operator++(int)
{
	// �˴���������Ч�ԣ�����ǰ�õ�������ʱ����Ҫ���
	StrBlobPtr ret = *this;		// ��¼��ǰ��ֵ
	++*this;					// ��ǰ�ƶ�һ��Ԫ�أ�ǰ��++��Ҫ����������Ч��
	return ret;					// ����֮ǰ��¼��״̬
}

inline StrBlobPtr StrBlobPtr::operator--(int)
{
	// �˴���������Ч�ԣ�����ǰ�õݼ�����ʱ����Ҫ���
	StrBlobPtr ret = *this;		// ��¼��ǰ��ֵ
	--*this;					// ����ƶ�һ��Ԫ�أ�ǰ��--��Ҫ���ݼ�����Ч��
	return ret;					// ����֮ǰ��¼��״̬
}

inline std::string& StrBlobPtr::operator*() const
{
	auto p = check(curr, "dereference past end");
	return (*p)[curr];
}

inline std::string* StrBlobPtr::operator->() const
{
	// ��ʵ�ʹ���ί�и������������
	return &this->operator*();
}

// ǰ׺���������ص�����Ķ��������
inline StrBlobPtr & StrBlobPtr::incr()
{
	check(curr, "increment past end of StrBlobPtr");
	++curr;
	return *this;
}

#endif
