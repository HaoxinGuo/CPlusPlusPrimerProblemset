#ifndef TEXT_QUERY_H
#define TEXT_QUERY_H

#include <vector>
#include <string>
#include <fstream>
#include <memory>
#include <map>
#include <set>

class QueryResult; // Ϊ�˶��庯��query�ķ������ͣ���������Ǳ����
class TextQuery {
public:
	using line_no = std::vector<std::string>::size_type;
	TextQuery(std::ifstream&);
	QueryResult query(const std::string&) const;

private:
	std::shared_ptr<std::vector<std::string>> file; // �����ļ�
	// ÿ�����ʵ������ڵ��кŵļ��ϵ�ӳ��
	std::map<std::string, std::shared_ptr<std::set<line_no>>> wm;
};

#endif // TEXT_QUERY_H
