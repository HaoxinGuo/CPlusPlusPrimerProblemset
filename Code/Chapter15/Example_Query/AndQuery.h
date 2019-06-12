#pragma once

#include <iostream>
#include <string>
#include <memory>
#include "BinaryQuery.h"
#include "QueryResult.h"
#include "Query_base.h"
#include "Query.h"

class AndQuery : public BinaryQuery {
	friend Query operator&(const Query&, const Query&);

	AndQuery(const Query &left, const Query &right) : BinaryQuery(left, right, "&")
	{
		PrintDebug("AndQuery::AndQuery(const Query &left, const Query &right)");
	}

	// ������ࣺAndQuery�̳���rep���Ҷ������������麯��
	QueryResult eval(const TextQuery&) const override;
};

inline Query operator&(const Query &lhs, const Query &rhs)
{
	return std::shared_ptr<Query_base>(new AndQuery(lhs, rhs));
};
