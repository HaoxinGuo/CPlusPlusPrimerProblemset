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

	// 抽象类：BinaryQuery不定义eval
	std::string rep() const
	{
		PrintDebug("BinaryQuery::rep");
		return "(" + lhs.rep() + " " + opSym + " " + rhs.rep() + ")";
	}

	Query lhs, rhs;		// 左侧和右侧的运算对象
	std::string opSym;	// 运算符的名字
};

