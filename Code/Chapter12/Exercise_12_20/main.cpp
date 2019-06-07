#include <iostream>

#include <fstream>

#include "StrBlob.h"

using namespace std;


int main()
{
	ifstream in("test.txt");
	
	if (!in) {
		cout << "Something is Wrong" << endl;
		return -1;
	}

	StrBlob sb;
	string word;

	while (in >> word)
	{
		sb.push_back(word);
	}

	auto beg = sb.begin();

	for (size_t i = 0; i < sb.size(); ++i)
	{
		cout << beg.deref() << " ";
		beg.incr();
	}

	cout << endl;
	cout << "--------------------" << endl;

	char ch;

	cin >> ch;

	return 0;
}
