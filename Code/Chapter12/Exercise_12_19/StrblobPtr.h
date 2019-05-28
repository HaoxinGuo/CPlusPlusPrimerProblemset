#ifndef STRBLOBPTR_H_INCLUDED
#define STRBLOBPTR_H_INCLUDED

#include<iostream>
#include<string>
#include<memory>
#include<vector>
#include<stdexcept>

using namespace std;

class Strblob;
class StrblobPtr
{
	friend  bool eq(const StrblobPtr&, const StrblobPtr&);

public:
	StrblobPtr();
	StrblobPtr(Strblob &a, size_t sz = 0) {};
	string& deref() const;
	StrblobPtr& incr();//前缀递增
	StrblobPtr& decr();//后缀递增

private:
	shared_ptr<vector<string>> check(size_t, const string&) const;
	weak_ptr<vector<string>> wptr;
	size_t curr;

};



#endif // !STRBLOBPTR_H_INCLUDED