#include "StrblobPtr.h"
#include "Strblob.h"

StrblobPtr::StrblobPtr() :curr(0) {};
//StrblobPtr::StrblobPtr(Strblob &a, size_t sz = 0) : wptr(a.data), curr(sz) {};

inline shared_ptr<vector<string>> StrblobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();//vector�Ƿ񻹴���
	if (!ret)
		throw runtime_error("unbound StrblobPtr");
	if (i > ret->size())
		throw out_of_range(msg);
	return ret;
}


inline
string & StrblobPtr::deref() const
{
	auto p = check(curr, "dereferebce past end");
	return (*p)[curr]; //(*p)�Ƕ�����ָ���vector;
	// TODO: �ڴ˴����� return ���
}

inline
StrblobPtr & StrblobPtr::incr()
{
	//���cur�Ѿ�ָ����������β��λ�ã��Ͳ��ܵ�����
	check(curr, "increment past end of StrblobPtr");
	++curr;						//�ƽ���ǰλ��
	return *this;
	// TODO: �ڴ˴����� return ���
}

inline
StrblobPtr & StrblobPtr::decr()
{
	//���curr�Ѿ�Ϊ0���ݼ����ͻ����һ���Ƿ��±�
	--curr;//�ݼ���ǰλ��
	check(-1, "decrement past begin of StrblobPtr");
	return *this;
	// TODO: �ڴ˴����� return ���
}



inline
bool eq(const StrblobPtr &lhs, const StrblobPtr &rhs)
{
	auto l = lhs.wptr.lock(), r = rhs.wptr.lock();
	if (l == r)
		return (!r || lhs.curr == rhs.curr);
	else
		return false;
}

