#pragma once
// ����һ������Query_base�̳���ϵ�Ľӿ���
#include <iostream>
#include <string>
#include <memory>

#include "QueryResult.h"
#include "TextQuery.h"
#include "Query_base.h"
#include "WordQuery.h"



class Query {
	// ��Щ�������Ҫ���ʽ���shared_ptr�Ĺ��캯�������ú�����˽�е�
	friend Query operator~(const Query &);
	friend Query operator|(const Query&, const Query&);
	friend Query operator&(const Query&, const Query&);

public:
	Query (const std::string &s) : q(new WordQuery(s))	// ����һ���µ�WordQuery
	{
		PrintDebug("Query::Query(const std::string &s)");
	}

	// �ӿں��������ö�Ӧ��Query_base����
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
	// Query::repͨ������Query_baseָ���rep()�����������
	return os << query.rep();
}
