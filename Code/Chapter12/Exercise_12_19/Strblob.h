#ifndef STRBLOB_H
#define STRBLOB_H


#include<iostream>
#include<string>
#include<memory>
#include<initializer_list>
#include<vector>
#include<stdexcept>
#include "StrBlobPtr.h"



using namespace std;
//提前声明，Strblob中的友类声明所需

class StrblobPtr;

class Strblob	
{
	friend class StrblobPtr;
public:
	typedef vector<string>::size_type size_type;	//别名

	Strblob();	//构造函数

	Strblob(initializer_list<string> i1); //利用初始划列表构造函数

	size_type size() const { return data->size(); };//返回data对象的大小

	bool empty() const { return data->empty(); };//检查data对象是否为空

	void push_back(const string &s) { data->push_back(s); };//在data对象中添加string函数

	void pop_back();//删除元素

	//元素访问
	string& front();
	const string& front() const;//常量版本

	string& back();
	const string& back() const;//常量版本


	//提供给StrblobPtr的接口

	StrblobPtr begin();
	StrblobPtr end();

private:
	shared_ptr<std::vector<std::string>> data;
	//如果data[i]不合法，抛出异常；
	void check(size_type i, const std::string &msg) const;
};




#endif // !STRBLOB_H


