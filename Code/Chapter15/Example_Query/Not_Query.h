#pragma once
#include "Query_base.h"
#include "Query.h"

class NotQuery : public Query_base {
	friend Query operator~(const Query&);

	NotQuery(const Query &q) : query(q)
	{
		PrintDebug("NotQuery::NotQuery(const Query &q)");
	}

	// ������ࣺNotQuery���������м̳ж����Ĵ��麯��
	std::string rep() const
	{
		PrintDebug("NotQuery::rep");
		return "~(" + query.rep() + ")";
	}

	QueryResult eval(const TextQuery&) const;
	Query query;
};

inline Query operator~(const Query &operand)
{
	return std::shared_ptr<Query_base>(new NotQuery(operand));
}

