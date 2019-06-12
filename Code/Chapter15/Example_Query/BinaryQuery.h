#pragma once
#include "Query_base.h"
#include "Query.h"

class BinaryQuery : public Query_base {
protected:
	BinaryQuery(const Query &l, const Query &r, std::string s) :
		lhs(l), rhs(r), opSym(s)
	{
		PrintDebug("BinaryQuery::BinaryQuery(const Query &l, const Query &r, std::string s)");
	}

	// �����ࣺBinaryQuery������eval
	std::string rep() const
	{
		PrintDebug("BinaryQuery::rep");
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}

	Query lhs, rhs;		// �����Ҳ���������
	std::string opSym;	// �����������
};

