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



// 这是一个抽象基类，具体的查询类型从中派生，所有成员都是private的
class Query_base {
	friend class Query;

protected:
	using line_no = TextQuery::line_no;
	virtual ~Query_base() = default;

private:
	// eval返回与当前Query匹配的QueryResult
	virtual QueryResult eval(const TextQuery&) const = 0;

	// rep是表示查询的一个string
	virtual std::string rep() const = 0;
};

