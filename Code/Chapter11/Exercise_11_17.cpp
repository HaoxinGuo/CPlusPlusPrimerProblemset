// ��ϰ11.17���ٶ�c��һ��string��multiset��v��һ��string��vector��
// ��������ĵ��á�ָ��ÿ�������Ƿ�Ϸ���

#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<string> v{"h", "a", "u"};
	multiset<string> c;

	copy(v.begin(), v.end(), inserter(c, c.end())); // �Ϸ�
	//copy(v.begin(), v.end(), back_inserter(c)); // �Ƿ���multisetû��push_back����
	copy(c.begin(), c.end(), inserter(v, v.end())); // �Ϸ�
	copy(c.begin(), c.end(), back_inserter(v));	// �Ϸ�

	return 0;
}
