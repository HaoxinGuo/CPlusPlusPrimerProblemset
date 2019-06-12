#include "OrQuery.h"
#include <algorithm>

QueryResult
OrQuery::eval(const TextQuery &text) const
{
	// ͨ��Query��Աlhs��rhs���������
	// ����eval����ÿ����������QueryResult
	auto right = rhs.eval(text), left = lhs.eval(text);

	// ��������������кſ��������set��
	auto ret_lines = std::make_shared<std::set<line_no>>(left.begin(), left.end());

	// �����Ҳ�����������õ��к�
	ret_lines->insert(right.begin(), right.end());

	// ����һ���µ�QueryResult������ʾlhs��rhs�Ĳ���
	return QueryResult(rep(), ret_lines, left.get_file());
}
