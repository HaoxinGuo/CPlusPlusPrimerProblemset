#pragma once
#include "Query_base.h"
#include "BinaryQuery.h"




class OrQuery : public BinaryQuery {
	friend Query operator|(const Query&, const Query&);

	OrQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "|")
	{
		PrintDebug("OrQuery::OrQuery(const Query &left, const Query &right)");
	}

	QueryResult eval(const TextQuery&) const override;
};

inline Query operator|(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new OrQuery(lhs, rhs));
}

