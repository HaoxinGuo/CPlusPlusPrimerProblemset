#pragma once

#include <iostream>
#include <string>
#include <memory>

#include "QueryResult.h"
#include "TextQuery.h"

static constexpr bool open_debug = false;
inline void PrintDebug(const char *msg)
{
	if (open_debug)
		std::cout << "[Debug] " << msg << "\n";
}
static QueryResult invalid_qr("", 0, 0);



// ����һ��������࣬����Ĳ�ѯ���ʹ������������г�Ա����private��
class Query_base {
	friend class Query;

protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;

private:
	// eval�����뵱ǰQueryƥ���QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;

	// rep�Ǳ�ʾ��ѯ��һ��string
	virtual std::string rep() const = 0;
};

