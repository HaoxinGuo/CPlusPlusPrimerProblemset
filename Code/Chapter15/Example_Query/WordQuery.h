#pragma once

#include "Query_base.h"
#include "QueryResult.h"
#include "TextQuery.h"

class WordQuery : public Query_base {
	friend class Query;		// Queryʹ��WordQuery���캯��

	WordQuery(const std::string &s) : query_word(s)
	{
		PrintDebug("WordQuery::WordQuery(const std::string &s)");
	}

	// ������ࣺWordQuery���������м̳ж����Ĵ��麯��
	QueryResult eval(const TextQuery &t) const override
	{
		return t.query(query_word);
	}

	std::string rep() const override
	{
		PrintDebug("WordQuery::rep");
		return query_word;
	}
	std::string query_word;	// Ҫ���ҵĵ���
};