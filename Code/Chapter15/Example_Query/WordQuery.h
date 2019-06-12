#pragma once

#include "Query_base.h"
#include "QueryResult.h"
#include "TextQuery.h"

class WordQuery : public Query_base {
	friend class Query;		// Query使用WordQuery构造函数

	WordQuery(const std::string &s) : query_word(s)
	{
		PrintDebug("WordQuery::WordQuery(const std::string &s)");
	}

	// 具体的类：WordQuery将定义所有继承而来的纯虚函数
	QueryResult eval(const TextQuery &t) const override
	{
		return t.query(query_word);
	}

	std::string rep() const override
	{
		PrintDebug("WordQuery::rep");
		return query_word;
	}
	std::string query_word;	// 要查找的单词
};