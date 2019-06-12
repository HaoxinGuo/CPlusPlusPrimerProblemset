#include<iostream>
#include <fstream>
#include <string>

#include "TextQuery.h"
#include "QueryResult.h"
#include "AndQuery.h"
#include "BinaryQuery.h"
#include "Not_Query.h"
#include "OrQuery.h"
#include "Query.h"
#include "Query_base.h"
#include "WordQuery.h"

using namespace std;

void runQueries(ifstream &infile)
{
	// infile��һ��ifstream��ָ������Ҫ������ļ�
	TextQuery tq(infile); // �����ļ���������ѯmap

	// ���û���������ʾ�û�����Ҫ��ѯ�ĵ��ʣ���ɲ�ѯ����ӡ���
	while (true)
	{
		cout << "Enter word to look for, or q to quit: ";
		string s;
		// ���������ļ�β���û�������qʱѭ����ֹ
		if (!(cin >> s) || s == "q") break;

		// ָ���ѯ����ӡ���
		print(cout, tq.query(s)) << endl;
	}
}

void func1()
{
	ifstream infile("little_story.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return;
	}

	runQueries(infile);
}

// ��ϰ15.36
void func2()
{
	Query q = (Query("fiery") & Query("bird")) | Query("wind");
	cout << q << endl;
}

// ��ϰ15.39
void func3()
{
	Query q0 = Query("Daddy");
	Query q1 = ~Query("Alice");
	Query q2 = Query("hair") | Query("Alice");
	Query q3 = Query("hair") & Query("Alice");
	Query q4 = (Query("fiery") & Query("bird")) | Query("wind");

	ifstream infile("little_story.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return;
	}

	TextQuery tq(infile);

	print(cout, q0.eval(tq));
	print(cout, q1.eval(tq));
	print(cout, q2.eval(tq));
	print(cout, q3.eval(tq));
	print(cout, q4.eval(tq));
}

// ��ϰ15.42��c��
void func4()
{
	Query q = ~Query("Alice");

	ifstream infile("little_story.txt");
	if (!infile)
	{
		cout << "Cant open file" << endl;
		return;
	}

	TextQuery tq(infile);

	std::pair<size_t, size_t> line_range{ 6, 10 };
	print(cout, q.eval(tq), &line_range);
}


int main() {
	//func1();
	func2();
	cout << "------------------" << endl;
	
	func3();
	cout << "------------------" << endl;
	
	func4();
	cout << "------------------" << endl;

	char ch;
	cin >> ch;
	return 0;
}