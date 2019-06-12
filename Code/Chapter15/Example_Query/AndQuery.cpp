#include "AndQuery.h"
#include <algorithm>
#include <iterator>
// ������������ѯ���set�Ľ���
QueryResult
AndQuery::eval(const TextQuery &text) const
{
	// ͨ��Query���������е�����ã��Ի���������Ĳ�ѯ���set
	auto left = lhs.eval(text), right = rhs.eval(text);

	// ����left��right������set
	auto ret_lines = std::make_shared<std::set<line_no>>();

	// ��������Χ�Ľ���д��һ��Ŀ�ĵ�������
	// ���ε��õ�Ŀ�ĵ�������ret���Ԫ��
	std::set_intersection(left.begin(), left.end(), right.begin(), right.end(), std::inserter(*ret_lines, ret_lines->begin()));

	return QueryResult(rep(), ret_lines, left.get_file());
}
