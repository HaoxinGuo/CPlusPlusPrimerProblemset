// ��ϰ11.13������һ��ĳ����У����������ִ���pair�ķ�������д�˳������
// ���汾���ֱ���ò�ͬ�ķ�������pair����������Ϊ������ʽ�����ڱ�д����⣬
// Ϊʲô��

#include <iostream>
#include <utility>
#include <string>
#include <vector>

using namespace std;

int main()
{
	vector<pair<string, int>> v;
	string w;
	int n;

	while (cin >> w >> n)
	{
		//v.push_back({w, n}); // �б��ʼ��
		//v.push_back(pair<string, int>(w, n)); // Ĭ�Ϲ��캯��
		//v.push_back(make_pair(w, n)); // ʹ��make_pair�����ܸ��ã����¼��ݣ��ɶ��Ժ�
		v.emplace_back(w, n); // ���Ա��⿽����Ч�ʸ���
	}

	for (const auto &p : v)
	{
		cout << p.first << "****" << p.second << endl;
	}

	return 0;
}
