#include "QueryResult.h"
using namespace std;

ostream &print(ostream &os, const QueryResult &qr, std::pair<size_t, size_t> *line_range)
{
	// ����ҵ��˵��ʣ���ӡ���ִ��������г��ֵ�λ��
	os << qr.sought << " occurs " << qr.lines->size() << " time(s)" << endl;

	// ��ӡ���ʳ��ֵ�ÿһ��
	for (auto num : *qr.lines) // ��set��ÿ������
		// �����кŴ�0��ʼ���û�����������
	{
		size_t line_num = num + 1;
		if (line_range && (line_num < line_range->first || line_num > line_range->second))
			continue;

		os << "\t(line " << num + 1 << ") "
			<< *(qr.file->begin() + num) << endl;
	}
	return os;
}
