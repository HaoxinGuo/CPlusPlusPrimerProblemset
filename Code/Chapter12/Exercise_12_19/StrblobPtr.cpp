#include "StrblobPtr.h"
#include "Strblob.h"

StrblobPtr::StrblobPtr() :curr(0) {};
//StrblobPtr::StrblobPtr(Strblob &a, size_t sz = 0) : wptr(a.data), curr(sz) {};

inline shared_ptr<vector<string>> StrblobPtr::check(size_t i, const string &msg) const {
	auto ret = wptr.lock();//vector是否还存在
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
	return (*p)[curr]; //(*p)是对象所指向的vector;
	// TODO: 在此处插入 return 语句
}

inline
StrblobPtr & StrblobPtr::incr()
{
	//如果cur已经指向了容器的尾后位置，就不能递增它
	check(curr, "increment past end of StrblobPtr");
	++curr;						//推进当前位置
	return *this;
	// TODO: 在此处插入 return 语句
}

inline
StrblobPtr & StrblobPtr::decr()
{
	//如果curr已经为0，递减它就会产生一个非法下标
	--curr;//递减当前位置
	check(-1, "decrement past begin of StrblobPtr");
	return *this;
	// TODO: 在此处插入 return 语句
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

