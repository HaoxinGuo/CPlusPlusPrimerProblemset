#include<iostream>
#include<string>
#include"date.h"

using namespace std;

int main() {
	string dates[] = {
		"Jan 1,2014","February 1 2014","Jan 30,2018","3/1/2019"
	};
	try {
		for (auto ds : dates) {
			date dl(ds);
			cout << dl;
			cout << "------------------------" << endl;
		}
	}
	catch (invalid_argument e) {
		cout << e.what() << endl;
	}
	char ch;
	cin >> ch;
	return 0;
}