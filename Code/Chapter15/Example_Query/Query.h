#pragma once
// 这是一个管理Query_base继承体系的接口类
#include <iostream>
#include <string>
#include <memory>

#include "QueryResult.h"
#include "TextQuery.h"
#include "Query_base.h"
#include "WordQuery.h"



class Query {
	// 这些运算符需要访问接受shared_ptr的构造函数，而该函数是私有的
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query (const std::string &s) : q(new WordQuery(s))	// 构建一个新的WordQuery
	{
		PrintDebug("Query::Query(const std::string &s)");
	}

	// 接口函数：调用对应的Query_base操作
	QueryResult eval(const TextQuery &t) const { return q->eval(t); }
	std::string rep() const
	{
		PrintDebug("Query::rep");
		return q->rep();
	}

private:
	Query(std::shared_ptr<Query_base> query) : q(query)
	{
		PrintDebug("Query::Query(std::shared_ptr<Query_base> query)");
	}

	std::shared_ptr<Query_base> q;
};

inline std::ostream& operator<<(std::ostream &os, const Query &query)
{
	// Query::rep通过它的Query_base指针对rep()进行了虚调用
	return os << query.rep();
}
